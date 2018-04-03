     setbuf(stdin, NULL);
     char buf[MAX_AUTHTOKEN_LEN];
     while (1) {
-	if (fgets(buf, sizeof(buf) - 1, stdin) == NULL) {
-	    fprintf(stdout, "BH input error\n");
-	    exit(0);
-	}
-	fprintf(stdout, "BH Kerberos authentication not supported\n");
+        if (fgets(buf, sizeof(buf) - 1, stdin) == NULL) {
+            fprintf(stdout, "BH input error\n");
+            exit(0);
+        }
+        fprintf(stdout, "BH Kerberos authentication not supported\n");
     }
 }
 #endif /* HAVE_GSSAPI */
