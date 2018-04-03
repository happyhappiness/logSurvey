 		fflush(logfile);
 	    }
 	    printf("$fail %s\n", request);
-	    printf("$message %s\n", msg[0] ? msg : "Unknown Error");
+	    printf("$message %s", msg[0] ? msg : "Unknown Error\n");
 	    printf("$end\n");
 	    fflush(stdout);
 	    continue;
