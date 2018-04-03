-/* $Id: tools.cc,v 1.5 1996/03/25 21:25:18 wessels Exp $ */
-
-#include "config.h"
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <signal.h>
-#include <unistd.h>		/* for sysconf() stuff */
-#include <malloc.h>
-#include <syslog.h>
-#include <sys/time.h>
-#include <sys/resource.h>
-#include <sys/wait.h>
-#include <sys/param.h>		/* has NOFILE */
-#include <sys/types.h>
-
-#include "debug.h"
-#include "cache_cf.h"
-#include "autoconf.h"
-
-void death(), deathb(), neighbors_rotate_log(), stat_rotate_log();
-void mail_warranty(), print_warranty(), _db_rotate_log();
+
+/* $Id: tools.cc,v 1.6 1996/03/27 01:46:26 wessels Exp $ */
+
+#include "squid.h"
+
 int do_mallinfo = 0;		/* don't do mallinfo() unless this gets set */
-int PrintRusage _PARAMS((void (*)(), FILE *));
-
-extern int catch_signals;	/* main.c */
-extern int storeWriteCleanLog _PARAMS((void));
-
-/*-------------------------------------------------------------------------
-void death()
-{
-    fprintf(stderr, "FATAL: Received Segment Violation...dying.\n");
-    signal(SIGSEGV, SIG_DFL);
-    signal(SIGBUS, SIG_DFL);
-    storeWriteCleanLog();
-    PrintRusage(NULL, stderr);
-    print_warranty();
-    abort();
-}
 
+static int PrintRusage _PARAMS((void (*)(), FILE *));
 
-void deathb()
-{
-    fprintf(stderr, "FATAL: Received bus error...dying.\n");
-    signal(SIGSEGV, SIG_DFL);
-    signal(SIGBUS, SIG_DFL);
-    signal(SIGBUS, SIG_DFL);
-    storeWriteCleanLog();
-    PrintRusage(NULL, stderr);
-    print_warranty();
-    abort();
-}
+extern int gethostname _PARAMS((char *name, int namelen));
 
 #define DEAD_MSG "\
 The Harvest Cache (version %s) died.\n\
