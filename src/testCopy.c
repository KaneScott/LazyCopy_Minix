#include <stdio.h>
#include <unistd.h>
#include <lib.h>
#include <fcntl.h>
#include <errno.h>

PUBLIC int count = 0;
int main(void){
	pid_t child;
	message m;
	int fd_from, c, savedFD;
	 ssize_t nread;
	const char *from;
	char buf[4096];
	from = "testCopy.c";
	fd_from = open(from, O_RDONLY);
	
	m.m_type = 49;
	m.m1_i1 = fd_from;
	_sendrec(FS, &m);
	savedFD = m.m1_i1;

	/*savedFD = m.m1_i1;*/
	m.m_type = 49;
	_sendrec(FS, &m);
	m.m_type = 49;
	m.m1_i1 = savedFD;
	_sendrec(FS, &m);
	
	read(fd_from, buf, sizeof buf);



	m.m_type =5;
	m.m1_i1 = savedFD;
	_sendrec(FS, &m);
		



	/*_sendrec(FS, &m)  ;*/

	read(m.m1_i1, buf, 126);
	/*
	fd_from = open(from, O_RD ONLY);
	m.m1_i1 = fd_from;
	printf("FD FROM: %d\n", fd_from);
	_sendrec(FS, &m);*/
	/*Do READ*/
	m.m_type = 3;
	m.m1_i2 = savedFD;
	m.m1_p1 = buf;
	_sendrec(FS, &m);
	
	/*m.m1_p1 = (char*)&count;*/
	
	
	

}
