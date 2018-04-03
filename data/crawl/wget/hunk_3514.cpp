 		   legible (expected_bytes - restval));
       logputs (LOG_VERBOSE, _(" (unauthoritative)\n"));
     }
-  timer = wtimer_new ();
+
   /* Get the contents of the document.  */
-  res = get_contents (dtsock, fp, len, restval, expected_bytes, &con->rbuf, 0);
-  con->dltime = wtimer_elapsed (timer);
-  wtimer_delete (timer);
+  res = get_contents (dtsock, fp, len, restval, expected_bytes, &con->rbuf,
+		      0, &con->dltime);
   tms = time_str (NULL);
   tmrate = retr_rate (*len - restval, con->dltime, 0);
   /* Close data connection socket.  */
