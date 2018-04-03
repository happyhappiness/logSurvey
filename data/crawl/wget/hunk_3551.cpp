 	    {
 	      logprintf (LOG_NOTQUIET,
 			 _("\nREST failed; will not truncate `%s'.\n"),
-			 u->local);
+			 con->target);
 	      CLOSE (csock);
 	      closeport (dtsock);
 	      rbuf_uninitialize (&con->rbuf);
