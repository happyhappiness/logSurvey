 #ifdef SQUID_SNMP
 	    snmpConnectionClose();
 #endif
-	    if (shutdown_pending) {
+	    if (shutting_down) {
 		normal_shutdown();
 	    } else {
-		fatal_dump("MAIN: SHUTDOWN from comm_select, but nothing pending.");
+		fatal_dump("MAIN: Unexpected SHUTDOWN from comm_select.");
 	    }
 	    break;
 	case COMM_TIMEOUT:
