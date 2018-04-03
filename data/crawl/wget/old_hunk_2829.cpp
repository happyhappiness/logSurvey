	  return err;
	case FTPRESTFAIL:
	  logputs (LOG_VERBOSE, _("\nREST failed, starting from scratch.\n"));
	  rest_failed = 1;
	  break;
	case FTPOK:
	  break;
