 {
     int opt, j, had_error = 0;
     dc *new_dc = NULL, *last_dc = NULL;
-    while (-1 != (opt = getopt(argc, argv, "bf"))) {
+    while (-1 != (opt = getopt(argc, argv, "bfl"))) {
 	switch (opt) {
 	case 'b':
 	    load_balance = 1;
 	    break;
 	case 'f':
 	    failover_enabled = 1;
 	    break;
+	case 'l':
+	    last_ditch_enabled = 1;
+	    break;
 	default:
 	    fprintf(stderr, "unknown option: -%c. Exiting\n", opt);
 	    usage();
