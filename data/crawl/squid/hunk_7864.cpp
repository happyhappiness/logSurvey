 		normal_shutdown();
 		exit(0);
 	    } else if (reread_pending) {
-		mainUninitialize();
-		mainInitialize();
+		mainReinitialize();
 		reread_pending = 0;	/* reset */
 	    } else {
 		fatal_dump("MAIN: SHUTDOWN from comm_select, but nothing pending.");
 	    }
+	    break;
 	default:
 	    fatal_dump("MAIN: Internal error -- this should never happen.");
 	    break;
