#include "student.h"
#include <stdlib.h>
#include <time.h>

struct stu* ini_STU(int num){
	struct stu *student= (struct stu*) malloc(sizeof(student));
	student->num = num;
	srand(time(NULL));
	student->times = rand() %(31-3)+3;
	student->state = 0;
	return student;
}
