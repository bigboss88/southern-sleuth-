#ifndef ta_h
#define ta_h
#include <pthread.h>
#include <unistd.h>
#include "student.h"
struct ta{
	int num;
	int timel;
	int busy;
	struct stu  *student;
};

struct ta* init_TA(int time,int num);
//void sleep(struct *ta);
void set_work(struct ta *ta,struct stu *stu);
//void work(struct ta *ta);
#endif
