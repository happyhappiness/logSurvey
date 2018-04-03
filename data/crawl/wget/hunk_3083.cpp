 		}
 	      else if (tml >= tmr)
 		logprintf (LOG_VERBOSE, _("\
-The sizes do not match (local %ld) -- retrieving.\n"), local_size);
+The sizes do not match (local %s) -- retrieving.\n"),
+			   number_to_static_string (local_size));
 	      else
 		logputs (LOG_VERBOSE,
 			 _("Remote file is newer, retrieving.\n"));
