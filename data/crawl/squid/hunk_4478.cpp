             switch ((r->callback(r->data, srv, srv->rbuf))) {	/*if non-zero reserve helper */
 
             case S_HELPER_UNKNOWN:
-                    fatal("helperStatefulHandleRead: either a non-state aware callback was give to the stateful helper routines, or an uninitialised callback response was recieved.\n");
+                    fatal("helperStatefulHandleRead: either a non-state aware callback was give to the stateful helper routines, or an uninitialised callback response was received.\n");
                 break;
 
             case S_HELPER_RELEASE:	/* helper finished with */
