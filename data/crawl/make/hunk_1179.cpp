 	{
 	  print_spaces (depth);
 	  if (d_mtime == (FILE_TIMESTAMP) -1)
-	    printf ("Dependency `%s' does not exist.\n", dep_name (d));
+	    printf (_("Dependency `%s' does not exist.\n"), dep_name (d));
 	  else
-	    printf ("Dependency `%s' is %s than dependent `%s'.\n",
-		    dep_name (d), d->changed ? "newer" : "older", file->name);
+	    printf (_("Dependency `%s' is %s than dependent `%s'.\n"),
+		    dep_name (d), d->changed ? _("newer") : _("older"), file->name);
 	  fflush (stdout);
 	}
     }