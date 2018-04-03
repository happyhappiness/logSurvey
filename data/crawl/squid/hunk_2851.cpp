                           srv->request ? (srv->request->placeholder ? 'P' : ' ') : ' ',
                                   tt < 0.0 ? 0.0 : tt,
                                   (int) srv->roffset,
-                                  srv->request ? log_quote(srv->request->buf) : "(none)");
+                                  srv->request ? Log::QuoteMimeBlob(srv->request->buf) : "(none)");
     }
 
     storeAppendPrintf(sentry, "\nFlags key:\n\n");
