 	  d = file->deps;
 	  while (d != 0)
 	    {
-	      if (d->file->updating)
+	      if (is_updating (d->file))
 		{
 		  error (NILF, _("Circular %s <- %s dependency dropped."),
 			 file->name, d->file->name);
