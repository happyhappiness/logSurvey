 #include <string.h>
 #endif
 
-int RFCNB_Timeout = 0;    /* Timeout in seconds ... */
+int RFCNB_Timeout = 0;          /* Timeout in seconds ... */
 
 int RFCNB_Discard_Rest(struct RFCNB_Con *con, int len);
 
 #ifdef NOT_USED
-void rfcnb_alarm(int sig)
-
+void
+rfcnb_alarm(int sig)
 {
 
     fprintf(stderr, "IO Timed out ...\n");
 
 }
 
-/* Set timeout value and setup signal handling */
-
-int RFCNB_Set_Timeout(int seconds)
+#endif /* NOT_USED */
 
+#ifdef NOT_USED
+/* Set timeout value and setup signal handling */
+int
+RFCNB_Set_Timeout(int seconds)
 {
     /* If we are on a Bezerkeley system, use sigvec, else sigaction */
 
