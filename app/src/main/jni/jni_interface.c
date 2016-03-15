#include <jni.h>
#include <string.h>
#include "com_example_pangb_jnitestproject_NdkJniUtils.h"
#include "./utils/android_log_print.h"
#include "./logic_logic_c/easy_encrypt.h"

JNIEXPORT jstring JNICALL Java_com_example_pangb_jnitestproject_NdkJniUtils_generateKey
  (JNIEnv *env, jobject object, jstring name)
  {
    char key[KEY_SIZE] = {0};
    memset(key, 0, sizeof(key));

    char temp[KEY_NAME_SIZE] = {0};

    const char* pName = (*env) -> GetStringUTFChars(env, name, NULL);

    if(NULL != pName)
    {
      strcpy(temp, pName);
      strcpy(key, generateKeyRAS(temp));

      (*env) -> ReleaseStringUTFChars(env, name, pName);
    }

    return (*env) -> NewStringUTF(env, key);
  }