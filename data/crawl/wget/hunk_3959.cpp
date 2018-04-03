     ou = u;
 
   /* First: establish the connection.  */
-  logprintf (LOG_VERBOSE, _("Connecting to %s:%hu... "), u->host, u->port);
-  err = make_connection (&sock, u->host, u->port);
-  switch (err)
+  if (u->proxy || !persistent_available_p (u->host, u->port))
     {
-    case HOSTERR:
-      logputs (LOG_VERBOSE, "\n");
-      logprintf (LOG_NOTQUIET, "%s: %s.\n", u->host, herrmsg (h_errno));
-      return HOSTERR;
-      break;
-    case CONSOCKERR:
-      logputs (LOG_VERBOSE, "\n");
-      logprintf (LOG_NOTQUIET, "socket: %s\n", strerror (errno));
-      return CONSOCKERR;
-      break;
-    case CONREFUSED:
-      logputs (LOG_VERBOSE, "\n");
-      logprintf (LOG_NOTQUIET,
-		 _("Connection to %s:%hu refused.\n"), u->host, u->port);
-      CLOSE (sock);
-      return CONREFUSED;
-    case CONERROR:
-      logputs (LOG_VERBOSE, "\n");
-      logprintf (LOG_NOTQUIET, "connect: %s\n", strerror (errno));
-      CLOSE (sock);
-      return CONERROR;
-      break;
-    case NOCONERROR:
-      /* Everything is fine!  */
-      logputs (LOG_VERBOSE, _("connected!\n"));
-      break;
-    default:
-      abort ();
-      break;
-    } /* switch */
+      logprintf (LOG_VERBOSE, _("Connecting to %s:%hu... "), u->host, u->port);
+      err = make_connection (&sock, u->host, u->port);
+      switch (err)
+	{
+	case HOSTERR:
+	  logputs (LOG_VERBOSE, "\n");
+	  logprintf (LOG_NOTQUIET, "%s: %s.\n", u->host, herrmsg (h_errno));
+	  return HOSTERR;
+	  break;
+	case CONSOCKERR:
+	  logputs (LOG_VERBOSE, "\n");
+	  logprintf (LOG_NOTQUIET, "socket: %s\n", strerror (errno));
+	  return CONSOCKERR;
+	  break;
+	case CONREFUSED:
+	  logputs (LOG_VERBOSE, "\n");
+	  logprintf (LOG_NOTQUIET,
+		     _("Connection to %s:%hu refused.\n"), u->host, u->port);
+	  CLOSE (sock);
+	  return CONREFUSED;
+	case CONERROR:
+	  logputs (LOG_VERBOSE, "\n");
+	  logprintf (LOG_NOTQUIET, "connect: %s\n", strerror (errno));
+	  CLOSE (sock);
+	  return CONERROR;
+	  break;
+	case NOCONERROR:
+	  /* Everything is fine!  */
+	  logputs (LOG_VERBOSE, _("connected!\n"));
+	  break;
+	default:
+	  abort ();
+	  break;
+	}
+    }
+  else
+    {
+      logprintf (LOG_VERBOSE, _("Reusing connection to %s:%hu.\n"), u->host, u->port);
+      sock = pc_last_fd;
+      reused_connection = 1;
+    }
 
   if (u->proxy)
     path = u->proxy->url;
