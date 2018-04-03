-/*
- * $Id$
- *
- * AUTHOR: Robert Collins
- *
- * SQUID Web Proxy Cache          http://www.squid-cache.org/
- * ----------------------------------------------------------
- *
- *  Squid is the result of efforts by numerous individuals from
- *  the Internet community; see the CONTRIBUTORS file for full
- *  details.   Many organizations have provided support for Squid's
- *  development; see the SPONSORS file for full details.  Squid is
- *  Copyrighted (C) 2001 by the Regents of the University of
- *  California; see the COPYRIGHT file for full details.  Squid
- *  incorporates software developed and/or copyrighted by other
- *  sources; see the CREDITS file for full details.
- *
- *  This program is free software; you can redistribute it and/or modify
- *  it under the terms of the GNU General Public License as published by
- *  the Free Software Foundation; either version 2 of the License, or
- *  (at your option) any later version.
- *
- *  This program is distributed in the hope that it will be useful,
- *  but WITHOUT ANY WARRANTY; without even the implied warranty of
- *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
- *  GNU General Public License for more details.
- *
- *  You should have received a copy of the GNU General Public License
- *  along with this program; if not, write to the Free Software
- *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
- *
- */
-
 #include "config.h"
+// tool functions still defined in protos.h - TODO extract
 #include "protos.h"
 
-int
-percent(int a, int b)
-{
-    return b ? ((int) (100.0 * a / b + 0.5)) : 0;
-}
+#define STUB_API "tools.cc"
+#include "tests/STUB.h"
 
-/* MinGW needs also a stub of death() */
-void
-death(int sig)
-{
-    fatal("tools.cc required");
-}
+int DebugSignal = -1;
+void releaseServerSockets(void) STUB
+char * dead_msg(void) STUB_RETVAL(NULL)
+void mail_warranty(void) STUB
+void dumpMallocStats(void) STUB
+void squid_getrusage(struct rusage *r) STUB
+double rusage_cputime(struct rusage *r) STUB_RETVAL(0)
+int rusage_maxrss(struct rusage *r) STUB_RETVAL(0)
+int rusage_pagefaults(struct rusage *r) STUB_RETVAL(0)
+void PrintRusage(void) STUB
+void death(int sig) STUB
+void BroadcastSignalIfAny(int& sig) STUB
+void sigusr2_handle(int sig) STUB
+void fatal(const char *message) STUB
+void fatal_common(const char *message) STUB
+void fatalf(const char *fmt,...) STUB
+void fatalvf(const char *fmt, va_list args) STUB
+void fatal_dump(const char *message) STUB
+void debug_trap(const char *message) STUB
+void sig_child(int sig) STUB
+void sig_shutdown(int sig) STUB
+const char * getMyHostname(void) STUB_RETVAL(NULL)
+const char * uniqueHostname(void) STUB_RETVAL(NULL)
+void leave_suid(void) STUB
+void enter_suid(void) STUB
+void no_suid(void) STUB
 
-void*
-xmemset(void* dst, int val, size_t sz)
+bool
+IamMasterProcess()
 {
-    assert(dst);
-    return memset(dst, val, sz);
+    //std::cerr << STUB_API << " IamMasterProcess() Not implemented\n";
+    // Since most tests run as a single process, this is the best default.
+    // TODO: If some test case uses multiple processes and cares about
+    // its role, we may need to parameterize or remove this stub.
+    return true;
 }
 
 bool
 IamWorkerProcess()
 {
-    fprintf(stderr, "Not implemented");
+    //std::cerr << STUB_API << " IamWorkerProcess() Not implemented\n";
     return true;
 }
 
 bool
 IamDiskProcess()
 {
-    fprintf(stderr, "Not implemented");
+    std::cerr << STUB_API << " IamDiskProcess() Not implemented\n";
     return false;
 }
 
-bool
-IamMasterProcess()
-{
-    fprintf(stderr, "Not implemented");
-    // Since most tests run as a single process, this is the best default.
-    // TODO: If some test case uses multiple processes and cares about
-    // its role, we may need to parameterize or remove this stub.
-    return true;
-}
-
 bool
 InDaemonMode()
 {
-    fprintf(stderr, "Not implemented");
+    std::cerr << STUB_API << " InDaemonMode() Not implemented\n";
     return false;
 }
 
 bool
 UsingSmp()
 {
-    fprintf(stderr, "Not implemented");
+    std::cerr << STUB_API << " UsingSnmp() Not implemented\n";
     return false;
 }
 
-void
-logsFlush(void)
-{
-    fatal("tools.cc required");
-}
+bool IamCoordinatorProcess() STUB_RETVAL(false)
+bool IamPrimaryProcess() STUB_RETVAL(false)
+int NumberOfKids() STUB_RETVAL(0)
+String ProcessRoles() STUB_RETVAL(String())
+void writePidFile(void) STUB
+pid_t readPidFile(void) STUB_RETVAL(0)
+void setMaxFD(void) STUB
+void setSystemLimits(void) STUB
+void squid_signal(int sig, SIGHDLR * func, int flags) STUB
+void logsFlush(void) STUB
+void kb_incr(kb_t * k, size_t v) STUB
+void debugObj(int section, int level, const char *label, void *obj, ObjPackMethod pm) STUB
+void parseEtcHosts(void) STUB
+int getMyPort(void) STUB_RETVAL(0)
+void setUmask(mode_t mask) STUB
+void strwordquote(MemBuf * mb, const char *str) STUB
+void keepCapabilities(void) STUB
+void restoreCapabilities(int keep) STUB
 
-void
-no_suid(void)
+void*
+xmemset(void* dst, int val, size_t sz)
 {
-    fatal("tools.cc required");
+    assert(dst);
+    return memset(dst, val, sz);
 }
