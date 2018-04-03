          can do but disable printing completely. */
       fprintf (stderr, _("\n%s received.\n"), redirect_request_signal_name);
       fprintf (stderr, _("%s: %s; disabling logging.\n"),
-	       logfile, strerror (errno));
+               logfile, strerror (errno));
       inhibit_logging = true;
     }
   save_context_p = false;
