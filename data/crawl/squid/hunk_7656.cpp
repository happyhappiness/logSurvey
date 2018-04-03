 void mail_warranty()
 {
     FILE *fp = NULL;
-    LOCAL_ARRAY(char, filename, 256);
-    LOCAL_ARRAY(char, command, 256);
-
-    sprintf(filename, "/tmp/mailin%d", (int) getpid());
-    fp = fopen(filename, "w");
-    if (fp != NULL) {
-	fprintf(fp, "From: %s\n", appname);
-	fprintf(fp, "To: %s\n", Config.adminEmail);
-	fprintf(fp, "Subject: %s\n", dead_msg());
-	fclose(fp);
-	sprintf(command, "mail %s < %s", Config.adminEmail, filename);
-	system(command);	/* XXX should avoid system(3) */
-	unlink(filename);
-    }
-}
-
-void print_warranty()
-{
-    if (Config.adminEmail)
-	mail_warranty();
-    else
-	puts(dead_msg());
+    char *filename;
+    static char command[256];
+    if ((filename = tempnam(NULL, appname)) == NULL)
+	return;
+    if ((fp = fopen(filename, "w")) == NULL)
+	return;
+    fprintf(fp, "From: %s\n", appname);
+    fprintf(fp, "To: %s\n", getAdminEmail());
+    fprintf(fp, "Subject: %s\n", dead_msg());
+    fclose(fp);
+    sprintf(command, "mail %s < %s", getAdminEmail(), filename);
+    system(command);		/* XXX should avoid system(3) */
+    unlink(filename);
 }
 
-
 static void dumpMallocStats(f)
      FILE *f;
 {
