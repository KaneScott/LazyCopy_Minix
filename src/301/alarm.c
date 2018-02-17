#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

int count = 0;

void sig_alarm(int sig){
  if(sig == SIGALRM){
    printf("Run count:");
    printf("%d\n",count);
    exit(0);
  }
}

int main(void){
	time_t startTime;
	int loopCount = 0;
	signal(SIGALRM, sig_alarm);
	alarm(60);      	
	while(1){
	  if(count % 100000 == 0){
	    int current; 
	    current = getpid();
	      printf("Process: %d\n", current);
	  }
	  loopCount = loopCount + 1;
	  if(loopCount > 1000){
	    loopCount = 0;
	    count = count +1;
	  }
	}


}
