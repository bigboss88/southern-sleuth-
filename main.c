#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "student.h"
#include <time.h>
#include "ta.h"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_t threads[4];
static int timea =0;
int gentime(int timeb){
	srand(time(NULL));
	return rand() %(timeb+1-0)+0;
}

int any_chairs(struct stu* chairs[],int num){
	int i=0;
	int j=0;
	for(i;i<num;i++){
		if(chairs[i]== NULL){
			j++;
		}
	}
	printf("%d\n",j );
	if(j!=0){return 1;}
	return 0;
}

int set_ta_job(struct ta *tas[],struct stu *stu){
	int i=0;
	for(i;i<4;i++){
		if(tas[i]->busy ==0){
			tas[i]->student =stu;
			tas[i]->busy=1;
			return 1;
		}
	}
	return 0;
}
void find_chair(struct stu* chairs[],int num,struct stu *stu){
	int i=0;
	for(i;i<num;i++){
		if(chairs[i] == NULL && stu->state!=1){
			chairs[i]=stu;
			stu->state=1;
			printf("Student %d is waiting for a ta \n",stu->num);
		}
	}
	return 1;
}

void work(void* t){
	printf("Doing Work\n");
	pthread_mutex_lock(&mutex);
	struct ta *td = (struct ta*) t;
	timea+=td->student->times;

	sleep(1);
	//sleep(td->student->times);
	td->timel = td->timel- td->student->times;
	td->busy =0;
	printf("Student %d is going to pass this assignment\n",td->student->num);
	td->student->state=2;
	pthread_mutex_unlock(&mutex);
}
void start_threads(struct ta *tas[]){
	int i=0;
	for(i;i<4;i++){
		if(tas[i]->busy==1){
			printf("Ctreating thread %d\n",i );
			pthread_create(threads[i],NULL,&work,(void *) tas[i]);
		}
	}
}

void join_threads(struct ta *tas[]){
	int i=0;
	for(i;i<4;i++){
		if(tas[i]->busy==0){
			pthread_join(threads[i],NULL);
		}
	}
}

int any_time(struct ta *tas[]){
	int i=0;
	for(i;i<4;i++){
		if(tas[i]->timel>0){return 1;}
	}
	return 0;
}

int clear(struct stu* chairs[],int num){
	int i=0;
	for(i;i<num;i++){
		if(chairs[i]->state ==2){
			chairs[i] ==NULL;
		}
	}
}

int main(int argc, char  *argv[]){
	if(argc!=4){
		printf("Wrong input format, should be ./a.out #chairs TA_Time Student_Time\n");
	}

	int num_chairs = atoi(argv[1]);
	int ta_Time = atoi(argv[2]);
	int stu_Time = atoi(argv[3]);
	struct ta* tas[4];
	int i=0;
	for(i;i<4;i++){
		tas[i]= init_TA(ta_Time,i);
	}
	int num_stu =0;
	struct stu* chairs[num_chairs];
	i=0;
	for(i;i<num_chairs;i++){
		chairs[i]=NULL;
	}

int steps =0;
	while(any_time(tas) ==1){
		int at=gentime(stu_Time);
		sleep(at);
		timea+=at;
		struct stu *student= ini_STU(num_stu);
		num_stu++;
		if(any_chairs(chairs,num_chairs)==0){
			printf("Student %d is not taking a chance in the lab with their assignment",student->num);
		}
		else{
			find_chair(chairs,num_chairs,student);
		}

		i=0;
		for(i;i<4;i++){
			set_ta_job(tas,&chairs[i]);
		}
		printf("Creating pthreads\n" );
		start_threads(tas);
		printf("Joinging pthreads\n" );
		join_threads(tas);
		sleep(1);
		printf("Time: %d\n",timea );
	}
}
