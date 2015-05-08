
#include "stdafx.h"
#include "es_uned_secsoftdev_scoring_model_ScoringModel3.h"


JNIEXPORT jstring JNICALL Java_es_uned_secsoftdev_scoring_model_ScoringModel3_event
(JNIEnv *env, jobject ref) {

	const char* str = "Event3";
	return env->NewStringUTF(str);
}

void good_function() {
	printf("GOOD\n");
}

void bad_function() {
	printf("BAD\n");
}

JNIEXPORT jdouble JNICALL Java_es_uned_secsoftdev_scoring_model_ScoringModel3_score
(JNIEnv *env, jobject ref, jstring args, jobjectArray vars) {

	jclass stringClass = env->FindClass("java/lang/String");
	const char * config = env->GetStringUTFChars(args, NULL);
	std::cout << "CONFIG: " << config << std::endl;

	if (strcmp(config, "POINTER") == 0) {

		static char buff[32];
		static void(*func_ptr)(void);
		func_ptr = &good_function;

		int i = 0;
		for (; i < 32 + 8; i++)
		{
			buff[i] = '»';
		}

		static void(*other_ptr)(void);
		other_ptr = &bad_function;
		char* dir = reinterpret_cast<char*>(&other_ptr);

		int size = strlen(dir);
		for (int j = 0; j < size; j++) {
			buff[i] = dir[j];
			i++;
		}

		(void)(*func_ptr)();
	}

	if (strcmp(config, "INTEGER") == 0) {

		int size = 4;
		int length = 0;
		char * src = (char *)calloc(size, size);
		for (int i = 0; i < 16; i++) {
			src[i] = '3';
		}

		char * comment = (char *)calloc(size, length);
		memcpy(comment, src, 16);

		printf("COMMENT: %s\n", comment);
		free(src);
		free(comment);
	}

	if (strcmp(config, "FORMAT") == 0) {

		char format[16];
		char buff[16];

		int size = env->GetArrayLength(vars);
		if (size > 1) {
			jobject v1 = env->GetObjectArrayElement(vars, 1);
			bool isString = env->IsInstanceOf(v1, stringClass) == JNI_TRUE;
			if (isString) {
				jstring value = (jstring)v1;
				const char * data = env->GetStringUTFChars(value, NULL);
				printf("Data length: %d", strlen(data));
				fflush(stdout);
				
				sprintf(buff, "Texto: %.8s", data);
				printf("Output: %s", buff);
				fflush(stdout);
			}
		}

		strcpy(format, "%08x%08x%08x%08x");
		printf(format, 1, 2, 3);
		fflush(stdout);

		printf("\xdc\xf5\x42\x01%08x%08x%08x%n");
	}

	if (strcmp(config, "FILE") == 0) {

		struct stat stat_info;
		if (stat("/tmp/test", &stat_info) == -1) {
			throw std::runtime_error("stat");
		}

		std::cout << stat_info.st_dev << std::endl;
		std::cout << stat_info.st_ino << std::endl;
		std::cout << stat_info.st_mode << std::endl;
		std::cout << stat_info.st_nlink << std::endl;
		std::cout << stat_info.st_uid << std::endl;
		std::cout << stat_info.st_gid << std::endl;
		std::cout << stat_info.st_rdev << std::endl;
		std::cout << stat_info.st_size << std::endl;
		std::cout << stat_info.st_atime << std::endl;
		std::cout << stat_info.st_mtime << std::endl;
		std::cout << stat_info.st_ctime << std::endl;

		FILE * file;
		if ((file = fopen("/tmp/test", "w")) == NULL) {
			throw std::runtime_error("open");
		}
		fputs("test", file);
		fclose(file);
	}

	const double s = 0.3;
	return s;
}

