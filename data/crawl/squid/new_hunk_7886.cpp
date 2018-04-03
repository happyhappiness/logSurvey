	    errcount++;
	    debug(1, 0, "Select loop Error. Retry. %d\n", errcount);
	    if (errcount == 10)
		fatal_dump("Select Loop failed.!");
	    break;
	case COMM_TIMEOUT:
	    /* this happens after 1 minute of idle time, or
