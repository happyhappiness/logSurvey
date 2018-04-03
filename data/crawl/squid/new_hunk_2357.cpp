#include "config.h"
// tool functions still defined in protos.h - TODO extract
#include "protos.h"

#define STUB_API "tools.cc"
#include "tests/STUB.h"

int DebugSignal = -1;
void releaseServerSockets(void) STUB
char * dead_msg(void) STUB_RETVAL(NULL)
void mail_warranty(void) STUB
void dumpMallocStats(void) STUB
void squid_getrusage(struct rusage *r) STUB
double rusage_cputime(struct rusage *r) STUB_RETVAL(0)
int rusage_maxrss(struct rusage *r) STUB_RETVAL(0)
int rusage_pagefaults(struct rusage *r) STUB_RETVAL(0)
void PrintRusage(void) STUB
void death(int sig) STUB
void BroadcastSignalIfAny(int& sig) STUB
void sigusr2_handle(int sig) STUB
void fatal(const char *message) STUB
void fatal_common(const char *message) STUB
void fatalf(const char *fmt,...) STUB
void fatalvf(const char *fmt, va_list args) STUB
void fatal_dump(const char *message) STUB
void debug_trap(const char *message) STUB
void sig_child(int sig) STUB
void sig_shutdown(int sig) STUB
const char * getMyHostname(void) STUB_RETVAL(NULL)
const char * uniqueHostname(void) STUB_RETVAL(NULL)
void leave_suid(void) STUB
void enter_suid(void) STUB
void no_suid(void) STUB

bool
IamMasterProcess()
{
    //std::cerr << STUB_API << " IamMasterProcess() Not implemented\n";
    // Since most tests run as a single process, this is the best default.
    // TODO: If some test case uses multiple processes and cares about
    // its role, we may need to parameterize or remove this stub.
    return true;
}

bool
IamWorkerProcess()
{
    //std::cerr << STUB_API << " IamWorkerProcess() Not implemented\n";
    return true;
}

bool
IamDiskProcess()
{
    std::cerr << STUB_API << " IamDiskProcess() Not implemented\n";
    return false;
}

bool
InDaemonMode()
{
    std::cerr << STUB_API << " InDaemonMode() Not implemented\n";
    return false;
}

bool
UsingSmp()
{
    std::cerr << STUB_API << " UsingSnmp() Not implemented\n";
    return false;
}

bool IamCoordinatorProcess() STUB_RETVAL(false)
bool IamPrimaryProcess() STUB_RETVAL(false)
int NumberOfKids() STUB_RETVAL(0)
String ProcessRoles() STUB_RETVAL(String())
void writePidFile(void) STUB
pid_t readPidFile(void) STUB_RETVAL(0)
void setMaxFD(void) STUB
void setSystemLimits(void) STUB
void squid_signal(int sig, SIGHDLR * func, int flags) STUB
void logsFlush(void) STUB
void kb_incr(kb_t * k, size_t v) STUB
void debugObj(int section, int level, const char *label, void *obj, ObjPackMethod pm) STUB
void parseEtcHosts(void) STUB
int getMyPort(void) STUB_RETVAL(0)
void setUmask(mode_t mask) STUB
void strwordquote(MemBuf * mb, const char *str) STUB
void keepCapabilities(void) STUB
void restoreCapabilities(int keep) STUB

void*
xmemset(void* dst, int val, size_t sz)
{
    assert(dst);
    return memset(dst, val, sz);
}
