#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main(void){
	time_t startTime;
	int count = 0;
	startTime = time(NULL);
       	while(1){
	  count = count +1;
	  if(count > 7){
	    printf("Triggered");
	    alarm(1);
	  }
	  if(time(NULL) > startTime + 5){
	    printf("Triggered");
	    alarm(1);
	  }
	}


	}
