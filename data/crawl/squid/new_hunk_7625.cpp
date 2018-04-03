		fatal_dump("MAIN: SHUTDOWN from comm_select, but nothing pending.");
	    }
	    break;
	case COMM_TIMEOUT:
		break;
	default:
	    fatal_dump("MAIN: Internal error -- this should never happen.");
	    break;
