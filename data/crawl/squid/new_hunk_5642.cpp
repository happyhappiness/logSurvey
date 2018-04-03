#include <sys/uio.h>
#include <sys/signal.h>
#include <string.h>
#include <syslog.h>
#include <signal.h>


int RFCNB_Timeout = 0;		/* Timeout in seconds ... */

void
rfcnb_alarm(int sig)
{
    syslog(LOG_ERR, "%s:%d: IO Timed out ...\n", __FILE__, __LINE__);
}

/* Set timeout value and setup signal handling */

int
RFCNB_Set_Timeout(int seconds)
{
#ifdef SA_RESTART
    struct sigaction sa;
#endif
    int x;
    RFCNB_Timeout = seconds;
    if (RFCNB_Timeout <= 0)
	return 0;
#ifdef SA_RESTART
    sa.sa_handler = rfcnb_alarm;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    x = sigaction(SIGALRM, &sa, NULL);
    ;
#else
    signal(SIGALRM, rfcnb_alarm);
#endif
    if (x < 0) {
	syslog(LOG_ERR, "%s:%d: signal/sigaction: %s", __FILE__, __LINE__, strerror(errno));
	return -1;
    }
    return 0;
}


/*
 * Discard the rest of an incoming packet as we do not have space for it
 * in the buffer we allocated or were passed ...
 */

int
RFCNB_Discard_Rest(struct RFCNB_Con *con, int len)
{
    char temp[100];		/* Read into here */
    int rest;
    int this_read;
    int bytes_read;

    /* len is the amount we should read */

