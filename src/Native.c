#include <stdio.h>
#include <jni.h>
#include "Native.h"

JNIEXPORT jint JNICALL Java_Native_instanceMethod(JNIEnv *env,
  jobject this, jintArray args) {
  jint len = (*env)->GetArrayLength(env, args);
  if (len <= 0){
    printf("C - array must have some length\n");
    return -1;
  }
  jint *arr = (*env)->GetIntArrayElements(env, args, NULL);
  jint smallest = -1;
  for (jint i=0; i < len;i++){
    if (arr[i] < 0) {
      printf("C - positive #'s only\n");
      return -1;
    }
    if (arr[i] < smallest || smallest == -1) {
      smallest = arr[i];
    }
  }
  return smallest;
}

JNIEXPORT jintArray JNICALL Java_Native_classMethod(JNIEnv *env, jclass class){
  jintArray jarr = (*env)->NewIntArray(env, 5);
  jint arr[] = {5, 4, 3, 10, 2};
  (*env)->SetIntArrayRegion(env, jarr, 0, 5, arr);
  return jarr;
}
