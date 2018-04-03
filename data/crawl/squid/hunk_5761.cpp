 	    /* notreached */
 	case NTLM_AUTHENTICATE:
 	    /* check against the DC */
-	    plen = strlen(buf) * 3 / 4; /* we only need it here. Optimization */
-	    signal(SIGALRM,timeout_during_auth);
+	    plen = strlen(buf) * 3 / 4;		/* we only need it here. Optimization */
+	    signal(SIGALRM, timeout_during_auth);
 	    alarm(30);
 	    cred = ntlm_check_auth((ntlm_authenticate *) decoded, plen);
 	    alarm(0);
-	    signal(SIGALRM,SIG_DFL);
+	    signal(SIGALRM, SIG_DFL);
 	    if (got_timeout != 0) {
-		fprintf(stderr,"ntlm-auth[%d]: Timeout during authentication.\n", getpid());
+		fprintf(stderr, "ntlm-auth[%d]: Timeout during authentication.\n", getpid());
 		SEND("BH Timeout during authentication");
-		got_timeout=0;
+		got_timeout = 0;
 		return;
 	    }
 	    if (cred == NULL) {
