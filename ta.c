#include "ta.h"
#include <unistd.h>
#include <pthread.h>
struct ta* init_TA(int time,int num){
  struct ta* nta =(struct ta*) malloc(sizeof(nta));
  nta->num =num;
  nta->timel =time;
  nta->student = NULL;
  nta->busy=0;
  return nta;
}

void set_work(struct ta *ta,struct stu *stu){
  ta->student = stu;
  stu->state=1;
}
