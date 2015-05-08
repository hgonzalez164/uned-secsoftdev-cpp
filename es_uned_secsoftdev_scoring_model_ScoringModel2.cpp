
#include "stdafx.h"
#include "es_uned_secsoftdev_scoring_model_ScoringModel2.h"


JNIEXPORT jstring JNICALL Java_es_uned_secsoftdev_scoring_model_ScoringModel2_event
(JNIEnv *env, jobject ref) {

	const char* str = "Event2";
	return env->NewStringUTF(str);
}

JNIEXPORT jdouble JNICALL Java_es_uned_secsoftdev_scoring_model_ScoringModel2_score
(JNIEnv *env, jobject ref, jstring args, jobjectArray vars) {

	const char * config = env->GetStringUTFChars(args, NULL);

	if (strcmp(config, "MALLOC") == 0) {
		size_t nsize = 0;
		char *p2;
		char *p = (char *)malloc(100);
		if ((p2 = (char *)realloc(p, nsize)) == NULL) {
			if (p) free(p);
			p = NULL;
			return NULL;
		}
		p = p2;
		free(p);
	}

	if (strcmp(config, "FREE") == 0) {

		char * p = (char *)malloc(10);
		free(p);
		free(p);
	}

	const double s = 0.2;
	return s;
}
