   if (sig && just_print_flag)
     return;
 
-  doneany = 0;
-  for (i = 0; i < FILE_BUCKETS; ++i)
-    for (f = files[i]; f != 0; f = f->next)
-      if (f->intermediate && (f->dontcare || !f->precious)
-	  && !f->secondary && !f->cmd_target)
-	{
-	  int status;
-	  if (f->update_status == -1)
-	    /* If nothing would have created this file yet,
-	       don't print an "rm" command for it.  */
-            continue;
- 	  if (just_print_flag)
-  	    status = 0;
-	  else
-	    {
-	      status = unlink (f->name);
-	      if (status < 0 && errno == ENOENT)
-		continue;
-	    }
-	  if (!f->dontcare)
-	    {
-	      if (sig)
-		error (NILF, _("*** Deleting intermediate file `%s'"), f->name);
-	      else
-                {
-                  if (! doneany)
-                    DB (DB_BASIC, (_("Removing intermediate files...\n")));
-                  if (!silent_flag)
-                    {
-                      if (! doneany)
-                        {
-                          fputs ("rm ", stdout);
-                          doneany = 1;
-                        }
-                      else
-                        putchar (' ');
-                      fputs (f->name, stdout);
-                      fflush (stdout);
-                    }
-                }
-	      if (status < 0)
-		perror_with_name ("unlink: ", f->name);
-	    }
-	}
+  file_slot = (struct file **) files.ht_vec;
+  file_end = file_slot + files.ht_size;
+  for ( ; file_slot < file_end; file_slot++)
+    if (! HASH_VACANT (*file_slot))
+      {
+	register struct file *f = *file_slot;
+	if (f->intermediate && (f->dontcare || !f->precious)
+	    && !f->secondary && !f->cmd_target)
+	  {
+	    int status;
+	    if (f->update_status == -1)
+	      /* If nothing would have created this file yet,
+		 don't print an "rm" command for it.  */
+	      continue;
+	    if (just_print_flag)
+	      status = 0;
+	    else
+	      {
+		status = unlink (f->name);
+		if (status < 0 && errno == ENOENT)
+		  continue;
+	      }
+	    if (!f->dontcare)
+	      {
+		if (sig)
+		  error (NILF, _("*** Deleting intermediate file `%s'"), f->name);
+		else
+		  {
+		    if (! doneany)
+		      DB (DB_BASIC, (_("Removing intermediate files...\n")));
+		    if (!silent_flag)
+		      {
+			if (! doneany)
+			  {
+			    fputs ("rm ", stdout);
+			    doneany = 1;
+			  }
+			else
+			  putchar (' ');
+			fputs (f->name, stdout);
+			fflush (stdout);
+		      }
+		  }
+		if (status < 0)
+		  perror_with_name ("unlink: ", f->name);
+	      }
+	  }
+      }
 
   if (doneany && !sig)
     {
