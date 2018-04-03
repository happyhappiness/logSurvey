 	fprintf(stderr, "         messages will be sent to 'stderr'.\n");
 	fflush(stderr);
 	debug_log = stderr;
-	/* avoid reduntancy */
 	stderr_enable = 0;
     }
 
