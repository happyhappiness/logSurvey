 
     if (gethostname(name, len) < 0) {	/* Error getting name */
 
-	strncpy(name, "unknown", len);
+        strncpy(name, "unknown", len);
 
-	/* Should check the error */
+        /* Should check the error */
 
 #ifdef DEBUG
-	fprintf(stderr, "gethostname in SMB_Get_My_Name returned error:");
-	perror("");
+        fprintf(stderr, "gethostname in SMB_Get_My_Name returned error:");
+        perror("");
 #endif
 
     }
