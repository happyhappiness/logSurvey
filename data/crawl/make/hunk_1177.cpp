 
       if (d->file->updating)
 	{
-	  error (NILF, "Circular %s <- %s dependency dropped.",
+	  error (NILF, _("Circular %s <- %s dependency dropped."),
 		 file->name, d->file->name);
 	  /* We cannot free D here because our the caller will still have
 	     a reference to it when we were called recursively via
