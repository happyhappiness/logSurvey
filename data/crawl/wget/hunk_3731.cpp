 	     .orig suffix. */
 	  if (!stat (u->local, &st))
 	    {
+              int eq_size;
+              int cor_val;
 	      /* Else, get it from the file.  */
 	      local_size = st.st_size;
 	      tml = st.st_mtime;
-	      if (local_size == f->size && tml >= f->tstamp)
+              /* Compare file sizes only for servers that tell us correct
+                 values. Assumme sizes being equal for servers that lie
+                 about file size.  */
+              cor_val = (con->rs == ST_UNIX || con->rs == ST_WINNT);
+              eq_size = cor_val ? (local_size == f->size) : 1 ;
+	      if (f->tstamp <= tml && eq_size)
 		{
-		  logprintf (LOG_VERBOSE, _("\
-Server file no newer than local file `%s' -- not retrieving.\n\n"), u->local);
+		  /* Remote file is older, file sizes can be compared and
+                     are both equal. */
+                  logprintf (LOG_VERBOSE, _("\
+Remote file no newer than local file `%s' -- not retrieving.\n"), u->local);
 		  dlthis = 0;
 		}
-	      else if (local_size != f->size)
-		{
-		  if (host_type == ST_VMS)
-		    {
-		      logprintf (LOG_VERBOSE, _("\
-Cannot compare sizes, remote system is VMS.\n"));
-		      dlthis = 0;
-		    }
-		  else
-		    {
-		      logprintf (LOG_VERBOSE, _("\
-The sizes do not match (local %ld) -- retrieving.\n"), local_size);
-		    }
-		}
-	    }
+	      else if (eq_size)
+                {
+                  /* Remote file is newer or sizes cannot be matched */
+                  logprintf (LOG_VERBOSE, _("\
+Remote file is newer than local file `%s' -- retrieving.\n\n"),
+                             u->local);
+                }
+              else
+                {
+                  /* Sizes do not match */
+                  logprintf (LOG_VERBOSE, _("\
+The sizes do not match (local %ld) -- retrieving.\n\n"), local_size);
+                }
+            }
 	}	/* opt.timestamping && f->type == FT_PLAINFILE */
       switch (f->type)
 	{
