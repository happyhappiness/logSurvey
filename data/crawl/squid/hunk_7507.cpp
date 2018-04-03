 	    if (!logfile)
 		fprintf(stderr, "Could not open dnsserver's log file\n");
 	    break;
-	case 't':
-	    dnsServerTCP = 1;
-	    break;
+	case 'h':
 	default:
-	    fprintf(stderr, "usage: dnsserver -h -d -p socket-filename\n");
+	    fprintf(stderr, "usage: dnsserver -hvd\n");
 	    exit(1);
 	    break;
 	}
     }
 
-    socket_from_cache = 3;
-
-    /* accept DNS look up from ipcache */
-    if (dnsServerTCP) {
-	fd = accept(socket_from_cache, NULL, NULL);
-	if (fd < 0) {
-	    fprintf(stderr, "dnsserver: accept: %s\n", xstrerror());
-	    exit(1);
-	}
-	close(socket_from_cache);
-	/* point stdout to fd */
-	dup2(fd, 1);
-	dup2(fd, 0);
-	if (fd > 1)
-	    close(fd);
-    }
     while (1) {
 	int retry_count = 0;
 	int addrbuf;