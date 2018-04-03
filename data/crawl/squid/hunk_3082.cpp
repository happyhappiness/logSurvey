     setbuf(stdin, NULL);
     char buf[6400];
     while (1) {
-	if (fgets(buf, sizeof(buf) - 1, stdin) == NULL) {
-	}
-	fprintf(stdout, "ERR\n");
-	fprintf(stderr, "LDAP group authorisation not supported\n");
+        if (fgets(buf, sizeof(buf) - 1, stdin) == NULL) {
+        }
+        fprintf(stdout, "ERR\n");
+        fprintf(stderr, "LDAP group authorisation not supported\n");
     }
 }
 #endif
