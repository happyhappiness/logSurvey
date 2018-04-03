
#if USE_ICMP

#include "ICMPv4.h"
#include "ICMPv6.h"
#include "ICMPPinger.h"

#ifdef _SQUID_MSWIN_

#include <winsock2.h>
#include <process.h>
#include "fde.h"

#define PINGER_TIMEOUT 5

/* windows uses the control socket for feedback to squid */
#define LINK_TO_SQUID squid_link

// windows still requires WSAFD but there are too many dependancy problems
// to just link to win32.cc where it is normally defined.

int
Win32__WSAFDIsSet(int fd, fd_set FAR * set)
{
    fde *F = &fd_table[fd];
    SOCKET s = F->win32.handle;

    return __WSAFDIsSet(s, set);
}

#else

#define PINGER_TIMEOUT 10

/* non-windows use STDOUT for feedback to squid */
#define LINK_TO_SQUID	1

#endif	/* _SQUID_MSWIN_ */

// ICMP Engines are declared global here so they can call each other easily.
ICMPPinger control;
ICMPv4 icmp4;
#if USE_IPV6
ICMPv6 icmp6;
#endif

int icmp_pkts_sent = 0;

int
main(int argc, char *argv[])
{
    fd_set R;
    int x;
    int max_fd = 0;

    struct timeval tv;
    const char *debug_args = "ALL,10";
    char *t;
    time_t last_check_time = 0;

    /*
     * cevans - do this first. It grabs a raw socket. After this we can
     * drop privs
     */
    int icmp4_worker = -1;
#if USE_IPV6
    int icmp6_worker = -1;
#endif
    int squid_link = -1;

    /* start by initializing the pinger debug cache.log-pinger */
    if ((t = getenv("SQUID_DEBUG")))
        debug_args = xstrdup(t);

    getCurrentTime();

    _db_init(NULL, debug_args);

    debugs(42, 0, "pinger: Initialising ICMP pinger ...");

    icmp4_worker = icmp4.Open();
    if(icmp4_worker < 0) {
        debugs(42, 0, "pinger: Unable to start ICMP pinger.");
    }
    max_fd = max(max_fd, icmp4_worker);

#if USE_IPV6
    icmp6_worker = icmp6.Open();
    if(icmp6_worker <0 ) {
        debugs(42, 0, "pinger: Unable to start ICMPv6 pinger.");
    }
    max_fd = max(max_fd, icmp6_worker);
#endif

    // abort if neither worker could open a socket.
    if(icmp4_worker == -1) {
#if USE_IPV6
        if(icmp6_worker == -1)
#endif
            debugs(42, 0, "FATAL: pinger: Unable to open any ICMP sockets.");
            exit(1);
    }

    if( (squid_link = control.Open()) < 0) {
        debugs(42, 0, "FATAL: pinger: Unable to setup Pinger control sockets.");
        icmp4.Close();
#if USE_IPV6
        icmp6.Close();
#endif
        exit(1); // fatal error if the control channel fails.
    }
    max_fd = max(max_fd, squid_link);

    setgid(getgid());
    setuid(getuid());

    for (;;) {
        tv.tv_sec = PINGER_TIMEOUT;
        tv.tv_usec = 0;
        FD_ZERO(&R);
        if(icmp4_worker >= 0) {
            FD_SET(icmp4_worker, &R);
        }
#if USE_IPV6

        if(icmp6_worker >= 0) {
            FD_SET(icmp6_worker, &R);
        }
#endif
        FD_SET(squid_link, &R);
        x = select(10, &R, NULL, NULL, &tv);
        getCurrentTime();

        if (x < 0) {
            debugs(42, 0, HERE << " FATAL Shutdown. select()==" << x << ", ERR: " << xstrerror());
            control.Close();
            exit(1);
        }

        if (FD_ISSET(squid_link, &R)) {
            control.Recv();
        }

#if USE_IPV6
        if (icmp6_worker >= 0 && FD_ISSET(icmp6_worker, &R)) {
            icmp6.Recv();
        }
#endif

        if (icmp4_worker >= 0 && FD_ISSET(icmp4_worker, &R)) {
            icmp4.Recv();
        }

        if (PINGER_TIMEOUT + last_check_time < squid_curtime) {
            if (send(LINK_TO_SQUID, &tv, 0, 0) < 0) {
                debugs(42, 0, "pinger: Closing. No requests in last " << PINGER_TIMEOUT << " seconds.");
                control.Close();
                exit(1);
            }

