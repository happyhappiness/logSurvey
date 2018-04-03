 	    loop_delay = (time_t) 0;
 	switch (comm_select(loop_delay, next_cleaning)) {
 	case COMM_OK:
-	    /* do nothing */
+	    errcount = 0;	/* reset if successful */
 	    break;
 	case COMM_ERROR:
 	    errcount++;
-	    debug(1, 0, "Select loop Error. Retry. %d\n", errcount);
+	    debug(1, 0, "Select loop Error. Retry %d\n", errcount);
 	    if (errcount == 10)
 		fatal_dump("Select Loop failed!");
 	    break;
