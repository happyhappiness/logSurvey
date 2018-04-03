     return;		/* useless */
 }
 
+static void
+usage(char *program)
+{
+    fprintf(stderr,"Usage: %s [-d] [-h]\n"
+	    	" -d      enable debugging\n"
+		" -h      this message\n",
+		program);
+}
 
 void
 process_options(int argc, char *argv[])
 {
     int opt;
 
-    while (-1 != (opt = getopt(argc, argv, "d"))) {
+    opterr = 0;
+    while (-1 != (opt = getopt(argc, argv, "dh"))) {
 	switch (opt) {
 	case 'd':
 	    debug_enabled = 1;
 	    break;
+	case 'h':
+	    usage(argv[0]);
+	    exit(0);
+	case '?':
+	    opt = optopt;
+	    /* fall thru to default */
 	default:
-	    warn("Unknown option: -%c. Exiting\n", opt);
+	    warn("Unknown option: -%c\n\n", opt);
+	    usage(argv[0]);
 	    exit(1);
 	    break;		/* not reached */
 	}
     }
     return;
 }
 
-
 void manage_request(void)
 {
     char buf[BUFFER_SIZE+1];
