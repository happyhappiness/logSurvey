 		{
 		  error (NILF, _("Circular %s <- %s dependency dropped."),
 			 file->name, d->file->name);
-		  if (lastd == 0)
+		  if (ld == 0)
 		    {
 		      file->deps = d->next;
                       free_dep (d);
