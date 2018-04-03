 DoOneRequest(char *buf)
 {
     RequestData requestData;
-    ParseBuffer (buf, &requestData);
+    ParseBuffer(buf, &requestData);
     if (!requestData.parsed) {
-	printf ("ERR\n");
+	printf("ERR\n");
 	return;
     }
     OutputHHA1(&requestData);
 }
 
+void
+ProcessArguments(int argc, char **argv)
+{
+    int i = 0;
+    if ((strncmp(argv[1], "-D", 2) != 0) || (argc < 3))
+	usage();
+    else {
+	backend = argv[2];
+	if (strcmp(backend, "LDAP") == 0) {
+	    i = LDAPArguments(argc, argv);
+	    if (i)
+		exit(i);
+	} else if (strcmp(backend, "file") == 0)
+	    TextArguments(argc, argv);
+	else
+	    usage();
+    }
+}
+
 int
 main(int argc, char **argv)
 {
     char buf[256];
     setbuf(stdout, NULL);
-    ProcessArguments (argc, argv);
+    ProcessArguments(argc, argv);
     while (fgets(buf, 256, stdin) != NULL)
-	DoOneRequest (buf);
+	DoOneRequest(buf);
     exit(0);
 }
