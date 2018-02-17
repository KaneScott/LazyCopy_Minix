#include <stdio.h>
#include <unistd.h>
#include <lib.h>

int main(void){
  Message m;
  m->m_type = 70;
	_sendrec(m);

}
