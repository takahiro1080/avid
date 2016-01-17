//***********************************************************************
// Copyright (c) 2015 takahiro1080.
// Distributed under the MIT license. See LICENSE file for details.
//***********************************************************************

// C library headers
#include <cstdio>

// C++ library headers
#include <iostream>

// other library headers

// avid library headers
#include "avid.hpp"


//***********************************************************************
//      forward declarations of the global functions
//***********************************************************************
namespace {

// Print command lines
void PrintCommandLines(int argc, char** argv);

// Print build informations
void PrintBuildInfo();

} // unnamed namespace


//***********************************************************************
//      main
//***********************************************************************
int main(int argc, char**argv) {

    using namespace std;

    cout << "Hello avid!!" << endl;

    ::PrintCommandLines(argc, argv);

    ::PrintBuildInfo();

    return getchar();
}



//***********************************************************************
//      definitions of the global functions
//***********************************************************************

namespace {

// Print command lines
void PrintCommandLines(int argc, char** argv) {

    using namespace std;

    for ( int i = 0; i < argc; i++ ) {
        cout << "argv[" << i << "] = " << argv[i] << endl;
    }

}


// Print build informations
void PrintBuildInfo() {

    using namespace std;

#if defined(_DEBUG) || defined(DEBUG)

    cout << "Build-Configuration --- Debug" << endl;

#else // #if defined(_DEBUG) || defined(DEBUG)

    cout << "Build-Configuration --- NotDebug" << endl;

#endif // #if defined(_DEBUG) || defined(DEBUG)


#ifdef AVID_OS_NAME

    cout << "Operating-System --- " << AVID_OS_NAME << endl;

#endif // #ifdef AVID_OS_NAME


#ifdef AVID_COMPILER_NAME

    cout << "Compiler --- " << AVID_COMPILER_NAME << endl;

#endif // #ifdef AVID_COMPILER_NAME

}


} // unnamed namespace




