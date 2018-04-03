         if (comm_iocallbackpending())
             comm_calliocallback();
 
-        int loop_delay = eventNextTime();
-
-        if (loop_delay < 0)
-            loop_delay = 0;
-
-        switch (comm_select(loop_delay)) {
-
-        case COMM_OK:
-            errcount = 0;	/* reset if successful */
-            break;
-
-        case COMM_ERROR:
-            errcount++;
-            debug(1, 0) ("Select loop Error. Retry %d\n", errcount);
-
-            if (errcount == 10)
-                fatal_dump("Select Loop failed!");
-
-            break;
-
-        case COMM_TIMEOUT:
-            break;
-
-        case COMM_SHUTDOWN:
-            SquidShutdown(NULL);
-
-            break;
-
-        default:
-            fatal_dump("MAIN: Internal error -- this should never happen.");
-
-            break;
-        }
+        mainLoop.runOnce();
     }
 
     /* NOTREACHED */
