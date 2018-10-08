#include "student.h"
#include <stdlib.h>
#include <time.h>

stu_t ini_STU(int num){
	stu_t student;
	student.num = num;
	srand(time(NULL));
	student.time = rand() %(31-3)+3;
	student.state = 0;
}