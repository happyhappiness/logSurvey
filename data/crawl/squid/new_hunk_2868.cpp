SQUIDCEXTERN const char *getMyHostname(void);
SQUIDCEXTERN const char *uniqueHostname(void);
SQUIDCEXTERN void safeunlink(const char *path, int quiet);

#include "fatal.h"
void death(int sig);
void sigusr2_handle(int sig);
void sig_child(int sig);
SQUIDCEXTERN void leave_suid(void);
