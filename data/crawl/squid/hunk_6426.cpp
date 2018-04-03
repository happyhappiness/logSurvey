 void
 sig_intr(int sig)
 {
-    printf("\rWaiting for open connections to finish...\n");
+    fprintf(stderr, "\rWaiting for open connections to finish...\n");
     signal(sig, SIG_DFL);
+    done_reading_urls = 1;
 }
 
 int
+
 open_http_socket(void)
 {
     int s;
