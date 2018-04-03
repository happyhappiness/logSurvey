#include <sys/uio.h>
#include <sys/signal.h>
#include <string.h>


int RFCNB_Timeout = 0;		/* Timeout in seconds ... */

void
rfcnb_alarm(int sig)
{

    fprintf(stderr, "IO Timed out ...\n");

}

/* Set timeout value and setup signal handling */

int
RFCNB_Set_Timeout(int seconds)
{
#ifdef __GLIBC__
    int temp;
#endif
    /* If we are on a Bezerkeley system, use sigvec, else sigaction */
#ifndef SA_RESTART
    struct sigvec invec, outvec;
#else
    struct sigaction inact, outact;
#endif

    RFCNB_Timeout = seconds;

    if (RFCNB_Timeout > 0) {	/* Set up handler to ignore but not restart */

#ifndef SA_RESTART
	invec.sv_handler = (void (*)()) rfcnb_alarm;
	invec.sv_mask = 0;
	invec.sv_flags = SV_INTERRUPT;

	if (sigvec(SIGALRM, &invec, &outvec) < 0)
	    return (-1);
#else
	inact.sa_handler = (void (*)()) rfcnb_alarm;
#ifdef SOLARIS
	/* Solaris seems to have an array of vectors ... */
	inact.sa_mask.__sigbits[0] = 0;
	inact.sa_mask.__sigbits[1] = 0;
	inact.sa_mask.__sigbits[2] = 0;
	inact.sa_mask.__sigbits[3] = 0;
#else
#ifdef __GLIBC__
	for (temp = 0; temp < 32; temp++)
	    inact.sa_mask.__val[temp] = 0;
#else
	/* AI - If you have problems with this line, contact the author */
	/* AI - This is the old line: inact.sa_mask = 0; */
	memset(&inact.sa_mask, 0, sizeof(inact.sa_mask));
#endif
#endif
	inact.sa_flags = 0;	/* Don't restart */

	if (sigaction(SIGALRM, &inact, &outact) < 0)
	    return (-1);

#endif

    }
    return (0);

}

/* Discard the rest of an incoming packet as we do not have space for it
 * in the buffer we allocated or were passed ...                         */

int
RFCNB_Discard_Rest(struct RFCNB_Con *con, int len)
{
    char temp[100];		/* Read into here */
    int rest, this_read, bytes_read;

    /* len is the amount we should read */

