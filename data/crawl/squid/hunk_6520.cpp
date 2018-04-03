 	    _res.options |= RES_DNSRCH;
 #endif
 	    break;
-	case 'd':
-	    snprintf(buf, 256, "dnsserver.%d.log", (int) getpid());
-	    logfile = fopen(buf, "a");
-	    do_debug++;
-	    if (!logfile)
-		fprintf(stderr, "Could not open dnsserver's log file\n");
-	    break;
-	case 'h':
-	    fprintf(stderr, "usage: dnsserver -hvd\n");
-	    exit(1);
-	    break;
 	case 's':
 	    if (opt_s == 0) {
 		_res.nscount = 0;
