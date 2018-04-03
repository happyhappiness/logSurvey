 	    {
 	      if (d->file->updating)
 		{
-		  error (NILF, _("Circular %s <- %s dependency dropped."),
+		  error (NILF, _("Circular %s <- %s prerequisite dropped."),
 			 file->name, d->file->name);
 		  if (lastd == 0)
 		    {
