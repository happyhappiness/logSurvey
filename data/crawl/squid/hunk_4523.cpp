     if ((e = strrchr(buf, '\r')))
 	*e = 0;
 
-    bindpasswd = (char *) calloc(sizeof(char), strlen(buf) + 1);
-    if (bindpasswd) {
-	strcpy(bindpasswd, buf);
-    } else {
+    bindpasswd = strdup(buf);
+    if (!bindpasswd) {
 	fprintf(stderr, PROGRAM_NAME " ERROR: can not allocate memory\n");
     }
 
