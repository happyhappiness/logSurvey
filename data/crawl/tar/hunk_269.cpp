   flush_read ();
   while (1)
     {
-      enum read_header status = read_header ();
+      enum read_header status = read_header (0);
 
       if (status == HEADER_FAILURE)
 	{
 	  int counter = 0;
 
-	  while (status == HEADER_FAILURE);
+	  do
 	    {
 	      counter++;
-	      status = read_header ();
+	      status = read_header (0);
 	    }
+	  while (status == HEADER_FAILURE);
+
 	  ERROR ((0, 0,
 		  _("VERIFY FAILURE: %d invalid header(s) detected"), counter));
 	}
