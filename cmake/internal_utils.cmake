
#*************************************************************************************************
#
#	avid/cmake/internal_utils.cmake
#
#*************************************************************************************************


#-------------------------------------------------------------------------------------------------
#		compiler and linker settings
#-------------------------------------------------------------------------------------------------
macro(fix_default_compiler_settings)
	if(MSVC)
		foreach(flag_var 
				CMAKE_CXX_FLAGS 
				CMAKE_CXX_FLAGS_DEBUG 
				CMAKE_CXX_FLAGS_RELEASE
				CMAKE_CXX_FLAGS_MINSIZEREL
				CMAKE_CXX_FLAGS_RELWITHDEBINFO)
			if(NOT BUILD_SHARED_LIBS)
				string(REPLACE "/MD" "-MT" ${flag_var} "${${flag_var}}")
			endif()
				string(REPLACE "/W3" "-W4" ${flag_var} "${${flag_var}}")
		endforeach()
	else()
		if(CMAKE_BUILD_TYPE STREQUAL "Debug")
			set(cxx_configuration_flags "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG -D_DEBUG")
		elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
			set(cxx_configuration_flags ${CMAKE_CXX_FLAGS_RELEASE})
		elseif(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
			set(cxx_configuration_flags ${CMAKE_CXX_FLAGS_MINSIZEREL})
		elseif(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
			set(cxx_configuration_flags ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
		endif()
	endif()
	
	set(AVID_OPTION_OUTBUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" CACHE PATH "output directory.")
	
endmacro()


macro(config_compiler_and_linker)
	fix_default_compiler_settings()
	if(MSVC)
		message("compiler --- MSVC")
		set(cxx_base_flags "-GS -W4 -WX -nologo -J -Zi")
		set(cxx_base_flags "${cxx_base_flags} -D_UNICODE -DUNICODE -DWIN32 -D_WIN32")
		set(cxx_base_flags "${cxx_base_flags} -DSTRICT -DWIN32_LEAN_AND_MEAN")
		set(cxx_exception_flags "-EHsc -D_HAS_EXCEPTIONS=1")
		set(cxx_no_exception_flags "-D_HAS_EXCEPTIONS=0")
		set(cxx_no_rtti_flags "-GR-")
	elseif(CMAKE_COMPILER_IS_GNUCXX)
		message("compiler --- GNUCXX")
		link_directories(C:/MinGW/bin)
		set(cxx_base_flags "-Wall -Wshadow")
		set(cxx_exception_flags "-fexceptions")
		set(cxx_no_exception_flags "-fno-exceptions")
		set(cxx_no_rtti_flags "-fno-rtti -DGTEST_HAS_RTTI=0")
		set(cxx_strict_flags "-Wextra -Wno-unused-parameter -Wno-missing-field-initializers")
	else()
		message("compiler --- NONE")
	endif()
	
	# for building avid's own tests and samples.
	set(cxx_exception "${CMAKE_CXX_FLAGS} ${cxx_base_flags} ${cxx_exception_flags}")
	set(cxx_no_exception "${CMAKE_CXX_FLAGS} ${cxx_base_flags} ${cxx_no_exception_flags}")
	set(cxx_default "${cxx_exception} ${cxx_configuration_flags}")
	set(cxx_no_rtti "${cxx_default} ${cxx_no_rtti_flags}")
	set(cxx_use_own_tuple "${cxx_default} -DGTEST_USE_OWN_TR1_TUPLE=1")
	
	# for building the avid libraries.
	set(cxx_strict "${cxx_default} ${cxx_strict_flags}")
endmacro()


# memo : ${CMAKE_CXX_COMPILER_ID} --- compiler name



#-------------------------------------------------------------------------------------------------
#		avid_set_target_directory
#-------------------------------------------------------------------------------------------------
function(avid_set_target_directory name)
	get_filename_component(target_directory ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
	file(RELATIVE_PATH target_directory ${PROJECT_SOURCE_DIR} ${target_directory})
	string(REPLACE src/ "" target_directory ${target_directory})
	string(REPLACE src "avid" target_directory ${target_directory})
	set_target_properties(${name} PROPERTIES FOLDER ${target_directory})
	message("	folder --- " ${target_directory})
endfunction()



#-------------------------------------------------------------------------------------------------
#		avid_set_target_output_directories
#-------------------------------------------------------------------------------------------------
function(avid_set_target_output_directories name)
	if(NOT MSVC)
		set(output_directory ${AVID_OPTION_OUTBUT_DIRECTORY}/$<CONFIG>)
		message("	output directory --- " ${output_directory})
		set_target_properties(${name} PROPERTIES
			ARCHIVE_OUTPUT_DIRECTORY ${output_directory}
			LIBRARY_OUTPUT_DIRECTORY ${output_directory}
			RUNTIME_OUTPUT_DIRECTORY ${output_directory}
			PDB_OUTPUT_DIRECTORY ${output_directory}/pdb)
	endif()
endfunction()



#-------------------------------------------------------------------------------------------------
#		avid_install_target_source_files
#-------------------------------------------------------------------------------------------------
function(avid_install_target_source_files sources extentions ignore_dirs)
	foreach(source IN LISTS sources)
		
		# extension
		get_filename_component(extention ${source} EXT)
		list(FIND extentions ${extention} is_find)
		if(is_find EQUAL -1)
			continue()
		endif()
		
		# ignore directory
		get_filename_component(parent_dir ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
		file(RELATIVE_PATH install_source ${parent_dir} ${source})
		set(is_install 1)
		foreach(ignore_dir IN LISTS ignore_dirs)
			string(FIND ${install_source} /${ignore_dir}/ is_ignore)
			if(NOT is_ignore EQUAL -1)
				set(is_install -1)
				break()
			endif()
		endforeach()
		
		# install
		if(is_install EQUAL 1)
			get_filename_component(directory ${source} DIRECTORY)
			get_filename_component(install_source ${source} NAME)
			file(RELATIVE_PATH install_dir ${PROJECT_SOURCE_DIR}/src ${directory})
			if(install_dir STREQUAL "")
				install(FILES ${source} DESTINATION include/)
				message("	install --- " ${CMAKE_INSTALL_PREFIX}/include/${install_source})
			else()
				install(FILES ${source} DESTINATION include/${install_dir})
				message("	install --- " ${CMAKE_INSTALL_PREFIX}/include/${install_dir}/${install_source})
			endif()
			
		endif()
	endforeach()
endfunction()



#-------------------------------------------------------------------------------------------------
#		avid_create_target_source_group
#-------------------------------------------------------------------------------------------------
function(avid_create_target_source_group name sources)
	foreach(source IN LISTS sources)
		get_filename_component(dir ${source} DIRECTORY)
		get_filename_component(current_dir ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
		file(RELATIVE_PATH path ${current_dir} ${dir})
		if(path)
			string(REPLACE / \\ group_dir ${path})
		else()
			set(group_dir "..\\")
		endif()
		source_group("source files\\${group_dir}" FILES ${source})
	endforeach()
endfunction()


#-------------------------------------------------------------------------------------------------
#		avid_target_link_libs
#-------------------------------------------------------------------------------------------------
function(avid_target_link_libs name libs)
	foreach(lib IN LISTS libs)
		message("	link --- " ${lib})
		add_dependencies(${name} ${lib})
		target_link_libraries(${name} ${lib})
	endforeach()
endfunction()



#-------------------------------------------------------------------------------------------------
#		avid_set_target_compile_flags
#-------------------------------------------------------------------------------------------------
function(avid_set_target_compile_flags name flags)
	if(flags)
		message("	flags --- " "${flags}")
		set_target_properties(${name} PROPERTIES COMPILE_FLAGS "${flags}")
	endif()
endfunction()



#-------------------------------------------------------------------------------------------------
#		avid_set_target_folder
#-------------------------------------------------------------------------------------------------
#function(avid_set_target_folder name)
#	if(USE_FOLDERS)
#		file(RELATIVE_PATH folder ${PROJECT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
#		set_target_properties(${name} PROPERTIES FOLDER ${folder})
#		message("	folder --- " ${folder})
#	endif()
#endfunction()



#-------------------------------------------------------------------------------------------------
#		avid_library_with_type_flags_libs
#-------------------------------------------------------------------------------------------------
function(avid_library_with_type_flags_libs name type flags libs)
	message("add library --- " ${name})
	add_library(${name} ${ARGN})
	
	foreach(source IN LISTS ARGN)
		message("	files --- " ${source})
	endforeach()
	
	# type
	message("	type --- " ${type})
	if(BUILD_SHARED_LIBS OR type STREQUAL "SHARED")
		set_target_properties(${name} PROPERTIES COMPILER_DEFINITIONS "AVID_BUILD_SHARED_LIBRARY=1")
	endif()
	
	# flags
	avid_set_target_compile_flags("${name}" "${flags}")
	
	# libs
	avid_target_link_libs("${name}" "${libs}")
	
	# folders
	#avid_set_target_folder("${name}")
	
	# source group
	avid_create_target_source_group("${name}" "${ARGN}")
	
	# install
	avid_install_target_source_files("${ARGN}" .hpp detail)
	
	# output
	avid_set_target_output_directories("${name}")
	
	# target directory
	avid_set_target_directory("${name}")
	
endfunction()





#-------------------------------------------------------------------------------------------------
#		avid_library_with_type_libs
#-------------------------------------------------------------------------------------------------
function(avid_library_with_type_libs name type libs)
	avid_library_with_type_flags_libs("${name}" "${type}" "${cxx_default}" "${libs}" ${ARGN})
endfunction()


#-------------------------------------------------------------------------------------------------
#		avid_shared_library
#-------------------------------------------------------------------------------------------------
function(avid_shared_library name libs)
	avid_library_with_type_libs("${name}" "SHARED" "${libs}" ${ARGN})
endfunction()



#-------------------------------------------------------------------------------------------------
#		avid_static_library
#-------------------------------------------------------------------------------------------------
function(avid_static_library name libs)
	avid_library_with_type_libs("${name}" "STATIC" "${libs}" ${ARGN})
endfunction()



#-------------------------------------------------------------------------------------------------
#		avid_library_ex
#-------------------------------------------------------------------------------------------------
function(avid_library_ex name libs)
	if(AVID_BUILD_SHARED_LIBRARY OR BUILD_SHARED_LIBS)
		avid_shared_library("${name}" "${libs}" ${ARGN})
	else()
		avid_static_library("${name}" "${libs}" ${ARGN})
	endif()
endfunction()



#-------------------------------------------------------------------------------------------------
#		avid_library
#-------------------------------------------------------------------------------------------------
function(avid_library name)
	file(GLOB_RECURSE files *.cpp *.hpp)
	get_filename_component(parent_dir ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
	avid_library_ex("${name}" "${ARGN}" "${files}" "${parent_dir}/${name}.hpp")
endfunction()





#-------------------------------------------------------------------------------------------------
#		avid_executable_with_flags_libs
#-------------------------------------------------------------------------------------------------
function(avid_executable_with_flags_libs name flags libs)
	message("add executable --- " ${name})
	add_executable(${name} ${ARGN})
	
	# flags
	avid_set_target_compile_flags("${name}" "${flags}")
	
	# libs
	avid_target_link_libs("${name}" "${libs}")
	
	# folders
	#avid_set_target_folder("${name}")
	
	# source group
	avid_create_target_source_group("${name}" "${ARGN}")
	
	# output
	avid_set_target_output_directories("${name}")
	
	# target directory
	avid_set_target_directory("${name}")
	
endfunction()



#-------------------------------------------------------------------------------------------------
#		avid_executable_with_libs
#-------------------------------------------------------------------------------------------------
function(avid_executable_with_libs name libs)
	avid_executable_with_flags_libs("${name}" "${cxx_default}" "${libs}" ${ARGN})
endfunction()



#-------------------------------------------------------------------------------------------------
#		avid_executable
#-------------------------------------------------------------------------------------------------
function(avid_executable name)
	file(GLOB_RECURSE files *.cpp *.hpp)
	avid_executable_with_libs("${name}" "${ARGN}" "${files}")
endfunction()





#-------------------------------------------------------------------------------------------------
#		avid_test_with_flags_libs
#-------------------------------------------------------------------------------------------------
function(avid_test_with_flags_libs name flags libs)
	avid_executable_with_flags_libs("${name}" "${flags}" "${libs}" ${ARGN})
	avid_set_target_directory("${name}" test)
	add_test(${name} ${name})
endfunction()



#-------------------------------------------------------------------------------------------------
#		avid_test_with_libs
#-------------------------------------------------------------------------------------------------
function(avid_test_with_libs name libs)
	avid_test_with_flags_libs("${name}" "${cxx_default}" "${libs}" ${ARGN})
endfunction()



#-------------------------------------------------------------------------------------------------
#		avid_test
#-------------------------------------------------------------------------------------------------
function(avid_test name)
	file(GLOB_RECURSE files *.cpp *.hpp)
	avid_test_with_libs("${name}" "${ARGN}" "${files}")
endfunction()









