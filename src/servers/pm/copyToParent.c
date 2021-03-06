#include "pm.h"
#include <sys/wait.h>
#include <minix/callnr.h>
#include <minix/com.h>
#include <signal.h>
#include "mproc.h"
#include "param.h"


PUBLIC int do_copytoparent(){
	int parentIndex;
	register struct mproc *rmp;
	void *ptr;
	int size;
	pid_t cpid;
	cpid = mp->mp_pid;
	parentIndex = mp->mp_parent;
	rmp = &mproc[parentIndex];
	printf("Called\n");
	ptr = (void*)m_in.m1_p1;
	size = m_in.m1_i1;
	if(mp->hasExec == 0){
		sys_vircopy(SELF, D, (vir_bytes)ptr, parentIndex, D, 			(vir_bytes)ptr, size );
	}
	return(OK);
}
