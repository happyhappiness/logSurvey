 	    printf("dnsserver version %s\n", SQUID_VERSION);
 	    exit(0);
 	    break;
+	case 'h':
 	default:
-	    fprintf(stderr, "usage: dnsserver -hvd\n");
+	    usage();
 	    exit(1);
 	    break;
 	}
     }
 
     for (;;) {
-	int retry_count = 0;
-	struct in_addr ip;
 	memset(request, '\0', REQ_SZ);
-
-	/* read from ipcache */
-	if (fgets(request, REQ_SZ, stdin) == NULL) {
+	if (fgets(request, REQ_SZ, stdin) == NULL)
 	    exit(1);
-	}
 	t = strrchr(request, '\n');
 	if (t == NULL)		/* Ignore if no newline */
 	    continue;
 	*t = '\0';		/* strip NL */
 	if ((t = strrchr(request, '\r')) != NULL)
 	    *t = '\0';		/* strip CR */
-	if (strcmp(request, "$shutdown") == 0) {
-	    exit(0);
-	}
-	if (strcmp(request, "$hello") == 0) {
-	    printf("$alive\n");
-	    printf("$end\n");
-	    fflush(stdout);
-	    continue;
-	}
-	result = NULL;
-	start = time(NULL);
-	/* check if it's already an IP address in text form. */
-	if (safe_inet_addr(request, &ip)) {
-#if NO_REVERSE_LOOKUP
-	    printf("$name %s\n", request);
-	    printf("$h_name %s\n", request);
-	    printf("$h_len %d\n", 4);
-	    printf("$ipcount %d\n", 1);
-	    printf("%s\n", request);
-	    printf("$aliascount %d\n", 0);
-	    printf("$end\n");
-	    fflush(stdout);
-	    continue;
-#endif
-	    for (;;) {
-		result = gethostbyaddr((char *) &ip.s_addr, 4, AF_INET);
-		if (result || h_errno != TRY_AGAIN)
-		    break;
-		if (++retry_count == 2)
-		    break;
-		sleep(2);
-	    }
-	} else {
-	    for (;;) {
-		result = gethostbyname(request);
-		if (result || h_errno != TRY_AGAIN)
-		    break;
-		if (++retry_count == 2)
-		    break;
-		sleep(2);
-	    }
-	}
-	stop = time(NULL);
-
-	msg[0] = '\0';
-	if (!result) {
-	    if (h_errno == TRY_AGAIN) {
-		snprintf(msg, 1024, "Name Server for domain '%s' is unavailable.\n",
-		    request);
-	    } else {
-		snprintf(msg, 1024, "DNS Domain '%s' is invalid: %s.\n",
-		    request, my_h_msgs(h_errno));
-	    }
-	}
-	if (!result || (strlen(result->h_name) == 0)) {
-	    if (logfile) {
-		fprintf(logfile, "%s %d\n", request, (int) (stop - start));
-		fflush(logfile);
-	    }
-	    printf("$fail %s\n", request);
-	    printf("$message %s", msg[0] ? msg : "Unknown Error\n");
-	    printf("$end\n");
-	    fflush(stdout);
-	    continue;
-	} else {
-
-	    printf("$name %s\n", request);
-	    printf("$h_name %s\n", result->h_name);
-	    printf("$h_len %d\n", result->h_length);
-
-	    addr_count = alias_count = 0;
-	    while (result->h_addr_list[addr_count] && addr_count < 255)
-		++addr_count;
-	    printf("$ipcount %d\n", addr_count);
-	    for (i = 0; i < addr_count; i++) {
-		struct in_addr addr;
-		xmemcpy((char *) &addr, result->h_addr_list[i], result->h_length);
-		printf("%s\n", inet_ntoa(addr));
-	    }
-
-#ifdef SEND_ALIASES
-	    while ((alias_count < 255) && result->h_aliases[alias_count])
-		++alias_count;
-#endif
-	    printf("$aliascount %d\n", alias_count);
-	    for (i = 0; i < alias_count; i++) {
-		printf("%s\n", result->h_aliases[i]);
-	    }
-
-#if LIBRESOLV_DNS_TTL_HACK
-	    /* DNS TTL handling - bne@CareNet.hu
-	     * for first try it's a dirty hack, by hacking getanswer
-	     * to place th e ttl in a global variable */
-	    if (_dns_ttl_ > -1)
-		printf("$ttl %d\n", _dns_ttl_);
-#endif
-
-	    printf("$end\n");
-	    fflush(stdout);
-	    continue;
-	}
+	lookup(request);
+	fflush(stdout);
     }
     /* NOTREACHED */
     return 0;
