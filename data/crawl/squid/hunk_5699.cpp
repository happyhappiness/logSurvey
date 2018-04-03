     NULL
 };
 
-void
-signal_received(int sig)
+static void usage(char *program)
 {
-    reset_pam = 1;
-    signal(sig, signal_received);
+    fprintf(stderr, "Usage: %s [options..]\n", program);
+    fprintf(stderr, " -n service_name\n");
+    fprintf(stderr, "           The PAM service name (default \"%s\")\n", DEFAULT_SQUID_PAM_SERVICE);
+    fprintf(stderr, " -t ttl    PAM connection ttl in seconds (default %d)\n", DEFAULT_SQUID_PAM_TTL);
+    fprintf(stderr, "           during this time the same connection will be reused\n");
+    fprintf(stderr, "           to authenticate all users\n");
+    fprintf(stderr, " -o        Do not perform account mgmt (account expiration etc)\n");
+    fprintf(stderr, " -1        Only one user authentication per PAM connection\n");
 }
 
 int
 main(int argc, char *argv[])
 {
     pam_handle_t *pamh = NULL;
-    int retval;
+    int retval = PAM_SUCCESS;
     char *user;
     /* char *password; */
     char buf[BUFSIZE];
     time_t pamh_created = 0;
-
-    signal(SIGHUP, signal_received);
+    int ttl = DEFAULT_SQUID_PAM_TTL;
+    char *service = DEFAULT_SQUID_PAM_SERVICE;
+    int no_acct_mgmt = 0;
 
     /* make standard output line buffered */
     setvbuf(stdout, NULL, _IOLBF, 0);
 
-    while (retval = PAM_SUCCESS, fgets(buf, BUFSIZE, stdin)) {
+    while (1) {
+	int ch = getopt(argc, argv, "1n:t:o");
+	switch (ch) {
+	case -1:
+		goto start;
+	case 'n':
+		service = optarg;
+		break;
+	case 't':
+		ttl = atoi(optarg);
+		break;
+	case '1':
+		ttl = 0;
+		break;
+	case 'o':
+		no_acct_mgmt = 1;
+		break;
+	default:
+		fprintf(stderr, "Unknown getopt value '%c'\n", ch);
+		usage(argv[0]);
+		exit(1);
+	}
+    }
+start:
+    if (optind < argc) {
+	fprintf(stderr, "Unknown option '%s'\n", argv[optind]);
+	usage(argv[0]);
+	exit(1);
+    }
+
+    while (fgets(buf, BUFSIZE, stdin)) {
 	user = buf;
 	password = strchr(buf, '\n');
 	if (!password) {
 	    fprintf(stderr, "authenticator: Unexpected input '%s'\n", buf);
-	    fprintf(stdout, "ERR\n");
-	    continue;
+	    goto error;
 	}
 	*password = '\0';
 	password = strchr(buf, ' ');
 	if (!password) {
 	    fprintf(stderr, "authenticator: Unexpected input '%s'\n", buf);
-	    fprintf(stdout, "ERR\n");
-	    continue;
+	    goto error;
 	}
 	*password++ = '\0';
 	conv.appdata_ptr = (char *) password;	/* from buf above. not allocated */
-#ifdef PAM_CONNECTION_TTL
-	if (pamh_created + PAM_CONNECTION_TTL >= time(NULL))
-	    reset_pam = 1;
-#endif
-	if (reset_pam && pamh) {
-	    /* Close previous PAM connection */
-	    retval = pam_end(pamh, retval);
+
+	if (ttl == 0) {
+	    /* Create PAM connection */
+	    retval = pam_start(service, user, &conv, &pamh);
 	    if (retval != PAM_SUCCESS) {
-		fprintf(stderr, "ERROR: failed to release PAM authenticator\n");
+		fprintf(stderr, "ERROR: failed to create PAM authenticator\n");
+		goto error;
 	    }
-	    pamh = NULL;
-	}
-	if (!pamh) {
-	    /* Initialize PAM connection */
-	    retval = pam_start(SQUID_PAM_SERVICE, "squid@", &conv, &pamh);
+	} else if (!pamh || (time(NULL) - pamh_created) >= ttl || pamh_created > time(NULL)) {
+	    /* Close previous PAM connection */
+	    if (pamh) {
+		retval = pam_end(pamh, retval);
+		if (retval != PAM_SUCCESS) {
+		    fprintf(stderr, "WARNING: failed to release PAM authenticator\n");
+		}
+		pamh = NULL;
+	    }
+	    /* Initialize persistent PAM connection */
+	    retval = pam_start(service, "squid@", &conv, &pamh);
 	    if (retval != PAM_SUCCESS) {
 		fprintf(stderr, "ERROR: failed to create PAM authenticator\n");
+		goto error;
 	    }
-	    reset_pam = 0;
 	    pamh_created = time(NULL);
 	}
-	if (retval == PAM_SUCCESS)
-	    retval = pam_set_item(pamh, PAM_USER, user);
-	if (retval == PAM_SUCCESS)
-	    retval = pam_set_item(pamh, PAM_CONV, &conv);
+	retval = PAM_SUCCESS;
+	if (ttl != 0) {
+	    if (retval == PAM_SUCCESS)
+		retval = pam_set_item(pamh, PAM_USER, user);
+	    if (retval == PAM_SUCCESS)
+		retval = pam_set_item(pamh, PAM_CONV, &conv);
+	}
 	if (retval == PAM_SUCCESS)
 	    retval = pam_authenticate(pamh, 0);
-	if (retval == PAM_SUCCESS)
+	if (retval == PAM_SUCCESS && !no_acct_mgmt)
 	    retval = pam_acct_mgmt(pamh, 0);
 	if (retval == PAM_SUCCESS) {
 	    fprintf(stdout, "OK\n");
 	} else {
+error:
 	    fprintf(stdout, "ERR\n");
 	}
+	if (ttl == 0) {
+	    retval = pam_end(pamh, retval);
+	    if (retval != PAM_SUCCESS) {
+		fprintf(stderr, "WARNING: failed to release PAM authenticator\n");
+	    }
+	    pamh = NULL;
+	}
     }
 
     if (pamh) {
