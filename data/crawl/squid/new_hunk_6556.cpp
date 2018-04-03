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
