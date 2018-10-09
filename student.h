#ifndef stu_h
#define stu_h
struct stu{
	int num;
	int times;
	int state; //if being helped or not
}stu_t;

struct stu init_STU(int num);
#endif
