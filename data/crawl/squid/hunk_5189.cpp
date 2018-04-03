 	exit(1);
     }
     f = fopen(passwdfile, "r");
+    if (NULL == f) {
+	fprintf(stderr, "%s: %s\n", passwdfile, xstrerror());
+	exit(1);
+    }
     while (fgets(buf, 8192, f) != NULL) {
 	if ((buf[0] == '#') || (buf[0] == ' ') || (buf[0] == '\t') ||
 	    (buf[0] == '\n'))