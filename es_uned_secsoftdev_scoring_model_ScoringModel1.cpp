
#include "stdafx.h"
#include "es_uned_secsoftdev_scoring_model_ScoringModel1.h"


JNIEXPORT jstring JNICALL Java_es_uned_secsoftdev_scoring_model_ScoringModel1_event
(JNIEnv *env, jobject ref) {

	const char* str = "Event1";
	return env->NewStringUTF(str);
}

JNIEXPORT jdouble JNICALL Java_es_uned_secsoftdev_scoring_model_ScoringModel1_score
(JNIEnv *env, jobject ref, jstring args, jobjectArray vars) {

	jclass stringClass = env->FindClass("java/lang/String");
	const char * config = env->GetStringUTFChars(args, NULL);
	std::cout << "CONFIG: " << config << std::endl;
	int size = env->GetArrayLength(vars);
	std::cout << "SIZE: " << size << std::endl;
	double s = 0.1;
	if (size > 1) {
		jobject v1 = env->GetObjectArrayElement(vars, 1);
		bool isString = env->IsInstanceOf(v1, stringClass) == JNI_TRUE;
		if (isString) {
			jstring value = (jstring)v1;
			const char * data = env->GetStringUTFChars(value, NULL);			
			char dest[1];
			char temp[1];
			temp[0] = 'X';
			strcpy(dest, config);
			std::cout << "DEST: " << dest << std::endl;
			std::cout << "TEMP: " << temp[0] << std::endl;
			if (temp[0] == 'X') {
				s = 0.2;
			}
		}
	}
	std::cout << "SCORE: " << s << std::endl;
	return s;
}

