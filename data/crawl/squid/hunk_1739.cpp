         }
 
         /* Send the HTTP request */
+        fprintf(stderr, "Sending HTTP request ... ");
         bytesWritten = mywrite(conn, msg, strlen(msg));
 
         if (bytesWritten < 0) {
