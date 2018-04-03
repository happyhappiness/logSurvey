 
     bindpasswd = xstrdup(buf);
     if (!bindpasswd) {
-        fprintf(stderr, PROGRAM_NAME " ERROR: can not allocate memory\n");
+        fprintf(stderr, PROGRAM_NAME ": ERROR: can not allocate memory\n");
     }
     fclose(f);
 
