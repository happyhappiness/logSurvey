 
 void
 psignal( int sig, const char* msg )
-  // purpose: print message, colon, space, signal name and LF.
-  // paramtr: sig (IN): signal number
-  //          msg (IN): message to prepend
+// purpose: print message, colon, space, signal name and LF.
+// paramtr: sig (IN): signal number
+//          msg (IN): message to prepend
 {
-  if ( msg && *msg ) fprintf( stderr, "%s: ", msg );
-  if ( sig > 0 && sig < _sys_nsig ) 
-    fprintf( stderr, "%s\n", _sys_siglist[sig] );
-  else
-    fputs( "(unknown)\n", stderr );
+    if ( msg && *msg ) fprintf( stderr, "%s: ", msg );
+    if ( sig > 0 && sig < _sys_nsig )
+        fprintf( stderr, "%s\n", _sys_siglist[sig] );
+    else
+        fputs( "(unknown)\n", stderr );
 }
 #endif // !HAS_PSIGNAL
 
 SigFunc*
 Signal( int signo, SigFunc* newhandler, bool doInterrupt )
-  // purpose: install reliable signals
-  // paramtr: signo (IN): signal for which a handler is to be installed
-  //          newhandler (IN): function pointer to the signal handler
-  //          doInterrupt (IN): interrupted system calls wanted!
-  // returns: the old signal handler, or SIG_ERR in case of error.
+// purpose: install reliable signals
+// paramtr: signo (IN): signal for which a handler is to be installed
+//          newhandler (IN): function pointer to the signal handler
+//          doInterrupt (IN): interrupted system calls wanted!
+// returns: the old signal handler, or SIG_ERR in case of error.
 {
-  struct sigaction action, old;
+    struct sigaction action, old;
 
-  memset( &old, 0, sizeof(old) );
-  memset( &action, 0, sizeof(action) );
+    memset( &old, 0, sizeof(old) );
+    memset( &action, 0, sizeof(action) );
 
-  // action.sa_handler = newhandler; I HATE TYPE-OVERCORRECTNESS !
-  memmove( &action.sa_handler, &newhandler, sizeof(SigFunc*) );
-  sigemptyset( &action.sa_mask );
+    // action.sa_handler = newhandler; I HATE TYPE-OVERCORRECTNESS !
+    memmove( &action.sa_handler, &newhandler, sizeof(SigFunc*) );
+    sigemptyset( &action.sa_mask );
 
-  if ( signo == SIGCHLD ) {
-    action.sa_flags |= SA_NOCLDSTOP;
+    if ( signo == SIGCHLD ) {
+        action.sa_flags |= SA_NOCLDSTOP;
 
 #ifdef SA_NODEFER
-    action.sa_flags |= SA_NODEFER;   // SYSV: don't block current signal
+        action.sa_flags |= SA_NODEFER;   // SYSV: don't block current signal
 #endif
-  }
+    }
 
-  if ( signo == SIGALRM || doInterrupt ) {
+    if ( signo == SIGALRM || doInterrupt ) {
 #ifdef SA_INTERRUPT
-    action.sa_flags |= SA_INTERRUPT; // SunOS, obsoleted by POSIX
+        action.sa_flags |= SA_INTERRUPT; // SunOS, obsoleted by POSIX
 #endif
-  } else {
+    } else {
 #ifdef SA_RESTART
-    action.sa_flags |= SA_RESTART;   // BSD, SVR4
+        action.sa_flags |= SA_RESTART;   // BSD, SVR4
 #endif
-  }
+    }
 
-  return ( sigaction( signo, &action, &old ) < 0 ) ? 
-    (SigFunc*) SIG_ERR : 
-    (SigFunc*) old.sa_handler;
+    return ( sigaction( signo, &action, &old ) < 0 ) ?
+           (SigFunc*) SIG_ERR :
+           (SigFunc*) old.sa_handler;
 }
 
 SIGRETTYPE
 sigChild( int signo )
-  // purpose: supply ad hoc child handler with output on stderr
-  // paramtr: signo (IN): == SIGCHLD
-  // returns: only if OS uses a return type for signal handler
-  // seealso: Stevens, UNP, figure 5.11 *and* Stevens, APUE, figure 8.3
+// purpose: supply ad hoc child handler with output on stderr
+// paramtr: signo (IN): == SIGCHLD
+// returns: only if OS uses a return type for signal handler
+// seealso: Stevens, UNP, figure 5.11 *and* Stevens, APUE, figure 8.3
 {
-  pid_t pid;
-  int  status = signo; // to stop GNU from complaining...
-  char line[128];
-
-  int saveerr = errno;
-  while ( (pid = waitpid( -1, &status, WNOHANG )) > 0 ) {
-    if ( WIFEXITED(status) ) {
-      sprintf( line, "child (pid=%ld) reaped, status %d\n%c", 
-	       (long) pid, WEXITSTATUS(status), 0 );
-    } else if ( WIFSIGNALED(status) ) {
-      sprintf( line, "child (pid=%ld) died on signal %d%s\n%c", 
-	       (long) pid, WTERMSIG(status),
+    pid_t pid;
+    int  status = signo; // to stop GNU from complaining...
+    char line[128];
+
+    int saveerr = errno;
+    while ( (pid = waitpid( -1, &status, WNOHANG )) > 0 ) {
+        if ( WIFEXITED(status) ) {
+            sprintf( line, "child (pid=%ld) reaped, status %d\n%c",
+                     (long) pid, WEXITSTATUS(status), 0 );
+        } else if ( WIFSIGNALED(status) ) {
+            sprintf( line, "child (pid=%ld) died on signal %d%s\n%c",
+                     (long) pid, WTERMSIG(status),
 #ifdef WCOREDUMP
-	       WCOREDUMP(status) ? " (core generated)" : "",
+                     WCOREDUMP(status) ? " (core generated)" : "",
 #else
-	       "",
+                     "",
 #endif
-	       0 );
-    } else {
-      sprintf( line, "detected dead child (pid=%ld), status %d\n%c",
-	       (long) pid, status, 0 );
+                     0 );
+        } else {
+            sprintf( line, "detected dead child (pid=%ld), status %d\n%c",
+                     (long) pid, status, 0 );
+        }
+        write( STDERR_FILENO, line, strlen(line) );
     }
-    write( STDERR_FILENO, line, strlen(line) );
-  }
-  errno = saveerr;
+    errno = saveerr;
 
 #if SIGRETTYPE != void
-  return 0;
+    return 0;
 #endif
 }
