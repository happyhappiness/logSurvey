	  return err;
	  break;
	case FTPRESTFAIL:
	  logputs (LOG_VERBOSE, _("\nREST failed, starting from scratch.\n"));
	  restval = 0L;
	  break;
