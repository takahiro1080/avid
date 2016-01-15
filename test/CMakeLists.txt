
#*************************************************************************************************
#
#	avid/test/CMakeLists.txt
#
#*************************************************************************************************


# framework test
if(AVID_OPTION_ENABLE_FRAMEWORK_TESTS)
	add_subdirectory(framework_test/)
endif()


# unit test
if(AVID_OPTION_ENABLE_UNIT_TESTS)
	add_subdirectory(unit_test/)
endif()



