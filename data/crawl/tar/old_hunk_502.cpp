#include <sgtty.h>
#include <sys/types.h>
#include <sys/socket.h>
#ifdef GENTAPE			/* e.g. ISC UNIX */
#include <sys/gentape.h>
#else
#include <sys/mtio.h>
#endif
#include <errno.h>

#if defined (i386) && defined (AIX)
#include <fcntl.h>
#endif

int	tape = -1;

char	*record;
int	maxrecsize = -1;
char	*checkbuf();

#define	SSIZE	64
char	device[SSIZE];
