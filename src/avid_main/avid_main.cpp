
#include <iostream>
#include <cstdio>


int main()
{
    using namespace std;

    cout << "Hello avid!!" << endl;


#if defined(_DEBUG) || defined(DEBUG)
    cout << "configuration --- Debug" << endl;
#else
    cout << "configuration --- Release" << endl;
#endif


#ifdef __GNUC__
    cout << "compiler --- GNU" << endl;
#endif
    
    return getchar();
}

