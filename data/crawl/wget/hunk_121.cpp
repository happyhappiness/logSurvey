       return false;
     }
 
+  if (continue_session)
+    {
+      ctx = (struct wgnutls_transport_context *) fd_transport_context (*continue_session);
+      if (!gnutls_session_is_resumed (session))
+        {
+          if (!ctx || !ctx->session_data || gnutls_session_set_data (session, ctx->session_data->data, ctx->session_data->size))
+            {
+              /* server does not want to continue the session */
+              gnutls_free (ctx->session_data->data);
+              gnutls_free (ctx->session_data);
+              gnutls_deinit (session);
+              return false;
+            }
+        }
+      else
+        {
+          logputs (LOG_ALWAYS, "SSL session has already been resumed. Continuing.\n");
+          continue_session = NULL;
+        }
+    }
+
   if (opt.connect_timeout)
     {
 #ifdef F_GETFL
