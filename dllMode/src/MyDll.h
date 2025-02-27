#ifndef MY_DLL_H
#define MY_DLL_H
#ifdef _WIN32
    #ifdef BUILD_MY_DLL
        #define DLL_API __declspec(dllexport)
    #else
        #define DLL_API __declspec(dllimport)
    #endif
#else
    #if defined(__GNUC__) && (__GNUC__ >= 4)
        #define DLL_API __attribute__((visibility("default")))
    #else
        #define DLL_API 
    #endif
#endif

DLL_API void my_function(void);
DLL_API int add(int a, int b);

#endif // MY_DLL_H
