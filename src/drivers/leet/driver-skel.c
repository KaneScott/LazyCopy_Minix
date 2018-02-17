/* This file contains the device dependent part of the drivers for the
 * following special files:
 *     /dev/leet		- leetspeak RAM disk 
 *
 */

 /* Includes */
#include "../drivers.h"
#include "../libdriver/driver.h"
#include <sys/ioc_memory.h>
#include "../../kernel/const.h"
#include "../../kernel/config.h"
#include "../../kernel/type.h"
#include "assert.h"
#include <string.h>


/* Function Prototypes */
FORWARD _PROTOTYPE(void l_init, (void));
FORWARD _PROTOTYPE(char *l_name, (void));
FORWARD _PROTOTYPE(int l_do_open, (struct driver *dp, message *m_ptr));
FORWARD _PROTOTYPE(int l_ioctl, (struct driver *dp, message *m_ptr));
FORWARD _PROTOTYPE(struct device *l_prepare, (int device));
FORWARD _PROTOTYPE(int l_transfer, (int proc_nr, int opcode, off_t position,
					iovec_t *iov, unsigned nr_req));
FORWARD _PROTOTYPE(void l_geometry, (struct partition *entry));


/* Entry points to this driver. */
PRIVATE struct driver l_dtab = {
	l_name,			/* current device's name */
	l_do_open,		/* open or mount */
	do_nop,			/* nothing on a close */
	l_ioctl,		/* specify ram disk geometry */
	l_prepare,		/* prepare for I/O on a given minor device */
	l_transfer,		/* do the I/O */
	nop_cleanup,	/* no need to clean up */
	l_geometry,		/* memory device "geometry" */
	nop_signal,		/* not needed */
	nop_alarm,		/* not needed */
	nop_cancel,  	/* not needed */
	nop_select,		/* not needed */
	NULL,
	NULL
};

/* Private variables */
PRIVATE struct device dv;


/*==========================================================================*
 *		main																*
 *==========================================================================*/
PUBLIC int main(void)
{
/* Initialise the device, and start the main driver loop */
	l_init();			
	driver_task(&l_dtab);		
	return(OK);				
}


/*==========================================================================*
 *		l_init																*
 *==========================================================================*/
PRIVATE void l_init()
{
/* TODO: Initialises the device structure dv */
}


/*==========================================================================*
 *		l_name																*
 *==========================================================================*/
PRIVATE char *l_name()
{
/* TODO: Return the name for the current device. */
	return NULL;
}


/*==========================================================================*
 *		l_do_open															*
 *==========================================================================*/
PRIVATE int l_do_open(struct driver *dp, message *m_ptr)
{
/* Nothing special to do here... just pretend that everything is all good. */
	return(OK);
}

/*==========================================================================*
 *		l_ioctl																*
 *==========================================================================*/
PRIVATE int l_ioctl(struct driver *dp, message *m_ptr)
{
/* TODO: perform ioctl */
}


/*==========================================================================*
 *		l_prepare															*
 *==========================================================================*/
PRIVATE struct device *l_prepare(int device)
{
/* TODO: Check that the minor number (device) is valid */
/* TODO: Return the appropriate device structure, or NIL_DEV if invalid */
	return NIL_DEV;
}

 
/*==========================================================================*
 *		l_transfer															*
 *==========================================================================*/
PRIVATE int l_transfer(proc_nr, opcode, position, iov, nr_req)
int proc_nr;		/* proc slot nr of proc makeing the sys call*/
int opcode;			/* DEV_GATHER (read) or DEV_SCATTER (write) */
off_t position;		/* offset on device to read or write        */
iovec_t *iov;		/* pointer to read or write request vector  */
unsigned nr_req;	/* length of request vector                 */
{
/* TODO: loop through all requests and perform the data transfers */
	return(OK);
}
 
/*==========================================================================*
 *		l_geometry															*
 *==========================================================================*/
PRIVATE void l_geometry(struct partition *entry)
{
/* TODO: fill out the number of heads, sectors, and cylinders */
}