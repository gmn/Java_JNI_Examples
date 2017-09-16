
//#include <stdlib.h>
#include <stdio.h>
#include "JavaNativeInterface.h" // javah generated header file

//implement the generated function declaration
JNIEXPORT jint JNICALL Java_JavaNativeInterface_printInt(JNIEnv *env, jobject obj, jint n) {
    printf( "(printing from C stdlib) Int is: %d\n", n );
    return n * n;
}
