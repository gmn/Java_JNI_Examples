#include <stdlib.h>
#include <stdio.h>
#include "JavaNativeInterface.h" // javah generated header file

JNIEXPORT jlong JNICALL Java_JavaNativeInterface_NewContext(JNIEnv *env, jobject obj) {
    int * data = calloc( 1000000, sizeof(int) );
    printf( "C: [1] got %lx\n", (unsigned long) data );
    return (long) data;
}

JNIEXPORT void JNICALL Java_JavaNativeInterface_FreeContext(JNIEnv *env, jobject obj, jlong ctx ) {
    int * data = (int *) ctx;
    printf( "C: [2] got %lx\n", (unsigned long) data );
    free( data );
}

