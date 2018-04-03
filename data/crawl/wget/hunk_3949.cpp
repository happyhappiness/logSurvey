 	      if (local_size == f->size && tml >= f->tstamp)
 		{
 		  logprintf (LOG_VERBOSE, _("\
-Server file no newer than local file `%s' -- not retrieving.\n\n"), u->local);
+Server file not newer than local file `%s' -- not retrieving.\n\n"), u->local);
 		  dlthis = 0;
 		}
 	      else if (local_size != f->size)
 		{
-		  logprintf (LOG_VERBOSE, _("\
+		  if (host_type == ST_VMS)
+		    {
+		      logprintf (LOG_VERBOSE, _("\
+Cannot compare sizes, remote system is VMS.\n"));
+		      dlthis = 0;
+		    }
+		  else
+		    {
+		      logprintf (LOG_VERBOSE, _("\
 The sizes do not match (local %ld) -- retrieving.\n"), local_size);
+		    }
 		}
 	    }
 	}	/* opt.timestamping && f->type == FT_PLAINFILE */
