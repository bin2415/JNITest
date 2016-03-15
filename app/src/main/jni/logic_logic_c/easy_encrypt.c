#include <string.h>
#include "easy_encrypt.h"
#include "./../utils/android_log_print.h"

char* generateKeyRAS(char* name)
{
    //�ж��β��Ƿ���Ч
    if (NULL == name || strlen(name) > KEY_NAME_SIZE) {
		LOGD("function generateKey must have a ok name!\n");
        return NULL;
    }

    //�����ֲ�����
    int index = 0;
    int loop = 0;
    char temp[KEY_SIZE] = {"\0"};
    //��������ڴ�
    memset(temp, 0, sizeof(temp));
    //����������name��������ʱ�ռ�
    strcpy(temp, name);
    //����ͨ��nameת������key���߼���������ģ����ԣ�ʵ���㷨���⸴��
    for (index=0; index<KEY_SIZE-1; index++)
    {
        temp[index] = 93;
        LOGD("---------------temp[%d]=%c", index, temp[index]);
    }

    return temp;
}