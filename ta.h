#ifndef stu_h
#define stu_h
#include <pthread.h>
#include <unistd.h>
#include "student.h"
struct ta{
	int num;
	int time;
	stu_t * student;
	pthread_t thread;
}ta_t;

ta_t init_TA(int time);
void sleep(ta_t *ta);
void set_work(ta_t *ta,stu_t *stu);
void work(ta_t);