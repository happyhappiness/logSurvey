     {
       if (where == lim)
 	{
-	  if (type)
+	  if (type && !silent)
 	    ERROR ((0, 0,
 		    _("Blanks in header where numeric %s value expected"),
 		    type));
