#include <sgtty.h>
#include <sys/types.h>
#include <sys/socket.h>
#ifdef HAVE_SYS_GENTAPE_H	/* e.g., ISC UNIX */
#include <sys/gentape.h>
#else
#include <sys/mtio.h>
#endif
#include <errno.h>

#if defined (_I386) && defined (_AIX)
#include <fcntl.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#else
long	lseek();
#endif

#ifdef STDC_HEADERS
#include <string.h>
#include <stdlib.h>
#else
extern char *malloc();
#endif

int	tape = -1;

char	*record;
int	maxrecsize = -1;
char	*checkbuf();
void	getstring();
void	error();

#define	SSIZE	64
char	device[SSIZE];
