#include <stdio.h>
#include <unistd.h>
#include <lib.h>
PUBLIC int count = 0;
int main(void){
	pid_t child;
	message m;
	child = fork();
	m.m_type = 49;
	m.m1_p1 = (char*)&count;
	m.m1_i1 = sizeof(int);
	while(1){
		 if(child != 0 && count >= 60){
			printf("Parent reached 60\n");
			break;		
		}
		else if(child == 0 && count <70){
			count++;
		}
		else{
			printf("Child calling do_copytoparent\n");
			_sendrec(MM, &m);
			break;
		}

	}
}
