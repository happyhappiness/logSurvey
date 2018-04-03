 	    break;
 	case COMM_ERROR:
 	    errcount++;
-	    debug(0, "Select loop Error. Retry. %d\n", errcount);
+	    debug(0, 0, "Select loop Error. Retry. %d\n", errcount);
 	    if (errcount == 10)
 		fatal_dump("Select Loop failed.!\n");
 	    break;
