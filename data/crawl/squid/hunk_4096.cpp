 usage()
 {
     fprintf(stderr,
-	"%s usage:\n%s [-A|D UserGroup][-O DefaultDomain][-d]\n"
-	"-A can specify a Windows Local Group name allowed to authenticate\n"
-	"-D can specify a Windows Local Group name not allowed to authenticate\n"
-	"-O can specify the default Domain against to authenticate\n"
-	"-d enable debugging.\n"
-	"-h this message\n\n",
-	my_program_name, my_program_name);
+            "%s usage:\n%s [-A|D UserGroup][-O DefaultDomain][-d]\n"
+            "-A can specify a Windows Local Group name allowed to authenticate\n"
+            "-D can specify a Windows Local Group name not allowed to authenticate\n"
+            "-O can specify the default Domain against to authenticate\n"
+            "-d enable debugging.\n"
+            "-h this message\n\n",
+            my_program_name, my_program_name);
 }
 
 void
 process_options(int argc, char *argv[])
 {
     int opt, had_error = 0;
     while (-1 != (opt = getopt(argc, argv, "dhA:D:O:"))) {
-	switch (opt) {
-	case 'A':
-	    safe_free(NTAllowedGroup);
-	    NTAllowedGroup=xstrdup(optarg);
-	    UseAllowedGroup = 1;
-	    break;
-	case 'D':
-	    safe_free(NTDisAllowedGroup);
-	    NTDisAllowedGroup=xstrdup(optarg);
-	    UseDisallowedGroup = 1;
-	    break;
-	case 'O':
-	    strncpy(Default_NTDomain, optarg, DNLEN);
-	    break;
-	case 'd':
-	    debug_enabled = 1;
-	    break;
-	case 'h':
-	    usage(argv[0]);
-	    exit(0);
-	case '?':
-	    opt = optopt;
-	    /* fall thru to default */
-	default:
-	    fprintf(stderr, "Unknown option: -%c. Exiting\n", opt);
-	    had_error = 1;
-	}
+        switch (opt) {
+        case 'A':
+            safe_free(NTAllowedGroup);
+            NTAllowedGroup=xstrdup(optarg);
+            UseAllowedGroup = 1;
+            break;
+        case 'D':
+            safe_free(NTDisAllowedGroup);
+            NTDisAllowedGroup=xstrdup(optarg);
+            UseDisallowedGroup = 1;
+            break;
+        case 'O':
+            strncpy(Default_NTDomain, optarg, DNLEN);
+            break;
+        case 'd':
+            debug_enabled = 1;
+            break;
+        case 'h':
+            usage(argv[0]);
+            exit(0);
+        case '?':
+            opt = optopt;
+            /* fall thru to default */
+        default:
+            fprintf(stderr, "Unknown option: -%c. Exiting\n", opt);
+            had_error = 1;
+        }
     }
     if (had_error) {
-	usage();
-	exit(1);
+        usage();
+        exit(1);
     }
 }
 
