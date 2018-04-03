         *t = '\0';
 
         if (r && cbdataReferenceValid(r->data)) {
-            switch ((r->callback(r->data, srv, srv->rbuf))) {	/*if non-zero reserve helper */
-
-            case S_HELPER_UNKNOWN:
-                fatal("helperStatefulHandleRead: either a non-state aware callback was give to the stateful helper routines, or an uninitialised callback response was received.\n");
-                break;
-
-            case S_HELPER_RELEASE:	/* helper finished with */
-
-                srv->flags.reserved = 0;
-
-                if ((srv->parent->OnEmptyQueue != NULL) && (srv->data))
-                    srv->parent->OnEmptyQueue(srv->data);
-
-                debugs(84, 5, "StatefulHandleRead: releasing " << hlp->id_name << " #" << srv->index + 1);
-
-                break;
-
-            case S_HELPER_RESERVE:	/* 'pin' this helper for the caller */
-
-        	srv->flags.reserved = 1;
-        	debugs(84, 5, "StatefulHandleRead: reserving " << hlp->id_name << " #" << srv->index + 1);
-
-                break;
-
-            default:
-                fatal("helperStatefulHandleRead: unknown stateful helper callback result.\n");
-            }
-
+            r->callback(r->data, srv, srv->rbuf);
         } else {
             debugs(84, 1, "StatefulHandleRead: no callback data registered");
+	    called = 0;
         }
 
         srv->flags.busy = 0;
