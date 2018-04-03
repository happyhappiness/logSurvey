  *
  * Returns:  a pointer to a static error
  *
- * Notes/Dependencies:  I got this from 
+ * Notes/Dependencies:  I got this from
  *      comp.os.ms-windows.programmer.win32
  */
-char * 
+char *
 map_windows32_error_to_string (DWORD ercode) {
 /* __declspec (thread) necessary if you will use multiple threads */
 __declspec (thread) static char szMessageBuffer[128];
- 
-	/* Fill message buffer with a default message in 
-	 * case FormatMessage fails 
+
+	/* Fill message buffer with a default message in
+	 * case FormatMessage fails
 	 */
-    wsprintf (szMessageBuffer, "Error %ld", ercode);
+    wsprintf (szMessageBuffer, "Error %ld\n", ercode);
 
 	/*
 	 *  Special code for winsock error handling.
