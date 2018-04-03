 	    }
 	    /* house keeping */
 	    break;
+	case COMM_SHUTDOWN:
+	    normal_shutdown();
+	    exit(0);
 	default:
 	    fatal_dump("MAIN: Internal error -- this should never happen.");
 	    break;
