#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "JavaNativeInterface.h" // javah generated header file

typedef struct context_s {
    char str[256];
} context_t;


JNIEXPORT jlong JNICALL Java_JavaNativeInterface_NewContext( JNIEnv *env, jobject obj ) {
    context_t * context = calloc( sizeof(context_t), 1 );
    printf( "C: [1] got %lx\n", (unsigned long) context );
    return (long) context;
}

JNIEXPORT void JNICALL Java_JavaNativeInterface_FreeContext( JNIEnv *env, jobject obj, jlong handle ) {
    context_t * context = (context_t *) handle;
    printf( "C: [2] got %lx\n", (unsigned long) context );
    free( context );
}

JNIEXPORT void JNICALL Java_JavaNativeInterface_Print( JNIEnv *env, jobject obj, jlong handle ) {
    context_t * context = (context_t *) handle;
    printf( "C printf: \"%s\"\n", context->str );
}

JNIEXPORT void JNICALL Java_JavaNativeInterface_SetStr( JNIEnv *env, jobject obj, jlong handle, jstring inJNIStr ) {
    const char *inCStr = (*env)->GetStringUTFChars(env, inJNIStr, NULL);
    if ( NULL == inCStr )
        return;

    context_t * context = (context_t *) handle;
    strncpy( context->str, inCStr, sizeof(context->str) );
    context->str[ sizeof(context->str) - 1 ] = '\0';

    (*env)->ReleaseStringUTFChars( env, inJNIStr, inCStr );  // release resources
}

JNIEXPORT jstring JNICALL Java_JavaNativeInterface_GetStr( JNIEnv *env, jobject obj, jlong handle ) {
    context_t * context = (context_t *) handle;
    return (*env)->NewStringUTF( env, context->str );
}

