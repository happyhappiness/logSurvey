 	  if (count != bufsize)
 	    {
 	      ERROR ((0, 0,
-		      _("File %s shrunk, padding with zeros"),
-		      name));
+		      _("File %s shrunk, padding with zeros"), quote (name)));
 	      return 1;
 	    }
 	  start = find_next_block ();
