 	      logprintf (LOG_NOTQUIET,
 			 _("\nREST failed; will not truncate `%s'.\n"),
 			 con->target);
-	      CLOSE (csock);
-	      CLOSE (dtsock);
-	      CLOSE (local_sock);
+	      xclose (csock);
+	      xclose (dtsock);
+	      xclose (local_sock);
 	      rbuf_uninitialize (&con->rbuf);
 	      return CONTNOTSUPPORTED;
 	    }
