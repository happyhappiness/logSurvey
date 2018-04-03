     }
 
   ctx = xnew0 (struct wgnutls_transport_context);
+  ctx->session_data = xnew0 (gnutls_datum_t);
   ctx->session = session;
+  if (gnutls_session_get_data2 (session, ctx->session_data))
+    {
+      xfree (ctx->session_data);
+      logprintf (LOG_NOTQUIET, "WARNING: Could not save SSL session data for socket %d\n", fd);
+    }
   fd_register_transport (fd, &wgnutls_transport, ctx);
   return true;
 }
