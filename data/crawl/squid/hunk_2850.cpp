                           srv->flags.shutdown ? 'S' : ' ',
                           tt < 0.0 ? 0.0 : tt,
                           (int) srv->roffset,
-                          srv->requests[0] ? log_quote(srv->requests[0]->buf) : "(none)");
+                          srv->requests[0] ? Log::QuoteMimeBlob(srv->requests[0]->buf) : "(none)");
     }
 
     storeAppendPrintf(sentry, "\nFlags key:\n\n");
