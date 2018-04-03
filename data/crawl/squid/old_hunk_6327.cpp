	    if (errcount == 10)
		fatal_dump("Select Loop failed!");
	    break;
	case COMM_SHUTDOWN:
	    /* delayed close so we can transmit while shutdown pending */
	    icpConnectionClose();
#if USE_HTCP
	    htcpSocketClose();
#endif
#ifdef SQUID_SNMP
	    snmpConnectionClose();
#endif
	    if (shutting_down) {
		normal_shutdown();
	    } else {
		fatal_dump("MAIN: Unexpected SHUTDOWN from comm_select.");
	    }
	    break;
	case COMM_TIMEOUT:
	    break;
	default:
	    fatal_dump("MAIN: Internal error -- this should never happen.");
	    break;
