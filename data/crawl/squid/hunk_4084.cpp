     if ((path == NULL) | (password == NULL) | (device == NULL)) {
 
 #ifdef DEBUG
-	fprintf(stderr, "Bad parameter passed to SMB_TreeConnect\n");
+        fprintf(stderr, "Bad parameter passed to SMB_TreeConnect\n");
 #endif
 
-	SMBlib_errno = SMBlibE_BadParam;
-	return (NULL);
+        SMBlib_errno = SMBlibE_BadParam;
+        return (NULL);
 
     }
     /* The + 2 is because of the \0 and the marker ...                    */
