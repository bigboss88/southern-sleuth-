#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "student.h"
#include "ta.h"

int main(int argc, char  *argv[]){
	if(argc!=4){
		printf("Wrong input format, should be ./a.out #chairs TA_Time Student_Time\n");
	}

	int num_chairs = atoi(argv[1]);
	int ta_Time = atoi(argv[2]);
	int stu_Time = atoi(argv[3]);
	ta_t tas[4];
	int time =0;
	int num_stu =0;
}