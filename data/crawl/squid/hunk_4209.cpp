 }				/* ARGSUSED */
 
 static void
-catchSignal(int sig)
-{
+catchSignal(int sig) {
     interrupted = 1;
     fprintf(stderr, "Interrupted.\n");
 }
 
 static void
-pipe_handler(int sig)
-{
+pipe_handler(int sig) {
     fprintf(stderr, "SIGPIPE received.\n");
 }
 
 static void
-set_our_signal(void)
-{
+set_our_signal(void) {
 #if HAVE_SIGACTION
 
     struct sigaction sa;
