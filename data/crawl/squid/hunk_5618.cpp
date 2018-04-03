     return domain;
 }
 
+static void
+usage(char *program)
+{
+    fprintf(stderr,"Usage: %s [-d] [-h] [domain]\n"
+	    	" -d      enable debugging\n"
+		" -hi     this message\n"
+		" domain  target domain, if different from the winbind configuration\n",
+		program);
+}
+
 char *
 process_options(int argc, char *argv[])
 {
     int opt;
     char *target_domain = NULL;
 
-    while (-1 != (opt = getopt(argc, argv, "d"))) {
+    while (-1 != (opt = getopt(argc, argv, "dh"))) {
 	switch (opt) {
 	case 'd':
 	    debug_enabled = 1;
 	    break;
+	case 'h':
+	    usage(argv[0]);
+	    exit(0);
 	default:
-	    warn("Unknown option: -%c. Exiting\n", opt);
+	    warn("Unknown option: -%c\n\n", opt);
+	    usage(argv[0]);
 	    exit(1);
 	    break;		/* not reached */
 	}
-	if (optind >= argc - 1) {
-	    target_domain = argv[optind];
-	    warn("target domain is %s\n", target_domain);
+    }
+    if (optind < argc) {
+	target_domain = argv[optind++];
+	warn("target domain is %s\n", target_domain);
+	if (optind < argc) {
+	    warn("Unknown argument: %s\n\n", argv[optind]);
+	    usage(argv[0]);
+	    exit(1);
 	}
     }
     return target_domain;