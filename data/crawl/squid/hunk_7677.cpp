 	    printf("$end\n");
 	    fflush(stdout);
 	    continue;
-	}
-	start = time(NULL);
-	result = gethostbyname(request);
-	if (!result) {
-	    if (h_errno == TRY_AGAIN) {
+#endif
+	    addrbuf = inet_addr(request);
+	    for (;;) {
+		result = gethostbyaddr(&addrbuf, 4, AF_INET);
+		if (result || h_errno != TRY_AGAIN)
+		    break;
+		if (++retry_count == 2)
+		    break;
+		sleep(2);
+	    }
+	} else {
+	    for (;;) {
+		result = gethostbyname(request);
+		if (result || h_errno != TRY_AGAIN)
+		    break;
+		if (++retry_count == 2)
+		    break;
 		sleep(2);
-		result = gethostbyname(request);	/* try a little harder */
 	    }
 	}
 	stop = time(NULL);
