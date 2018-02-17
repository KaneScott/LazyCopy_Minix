/* $Header: /cvsup/minix/src/lib/libp/asz.c,v 1.1.1.1 2005/04/21 14:56:22 beng Exp $ */
/*
 * (c) copyright 1983 by the Vrije Universiteit, Amsterdam, The Netherlands.
 *
 *          This product is part of the Amsterdam Compiler Kit.
 *
 * Permission to use, sell, duplicate or disclose this software must be
 * obtained in writing. Requests for such permissions may be sent to
 *
 *      Dr. Andrew S. Tanenbaum
 *      Wiskundig Seminarium
 *      Vrije Universiteit
 *      Postbox 7161
 *      1007 MC Amsterdam
 *      The Netherlands
 *
 */

/* Author: J.W. Stevenson */

struct descr {
	int	low;
	int	diff;
	int	size;
};

int _asz(dp) struct descr *dp; {
	return(dp->size * (dp->diff + 1));
}
