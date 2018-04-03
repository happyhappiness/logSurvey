
/* $Id: tools.cc,v 1.6 1996/03/27 01:46:26 wessels Exp $ */

#include "squid.h"

int do_mallinfo = 0;		/* don't do mallinfo() unless this gets set */

static int PrintRusage _PARAMS((void (*)(), FILE *));

extern int gethostname _PARAMS((char *name, int namelen));

#define DEAD_MSG "\
The Harvest Cache (version %s) died.\n\
