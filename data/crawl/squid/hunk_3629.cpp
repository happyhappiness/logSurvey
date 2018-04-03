                           srv->flags.reserved ? 'R' : ' ',
                           srv->flags.shutdown ? 'S' : ' ',
                           srv->request ? (srv->request->placeholder ? 'P' : ' ') : ' ',
-                          tt < 0.0 ? 0.0 : tt,
-                          srv->flags.reserved || tr > 0.0 ? tr : 0.0,
-                          (int) srv->roffset,
-                          srv->request ? log_quote(srv->request->buf) : "(none)");
+                                  tt < 0.0 ? 0.0 : tt,
+                                  (int) srv->roffset,
+                                  srv->request ? log_quote(srv->request->buf) : "(none)");
     }
 
     storeAppendPrintf(sentry, "\nFlags key:\n\n");