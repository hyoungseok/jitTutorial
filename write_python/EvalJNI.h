/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class EvalJNI */

#ifndef _Included_EvalJNI
#define _Included_EvalJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     EvalJNI
 * Method:    loadModel
 * Signature: (Ljava/lang/String;)J
 */
JNIEXPORT jlong JNICALL Java_EvalJNI_loadModel
  (JNIEnv *, jobject, jstring);

/*
 * Class:     EvalJNI
 * Method:    evaluate
 * Signature: (J[FI)[F
 */
JNIEXPORT jfloatArray JNICALL Java_EvalJNI_evaluate
  (JNIEnv *, jobject, jlong, jfloatArray, jint);

#ifdef __cplusplus
}
#endif
#endif
