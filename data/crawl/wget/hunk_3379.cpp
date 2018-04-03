       fprintf (fp, "  ");
       if (f->tstamp != -1)
 	{
-	  /* #### Should we translate the months? */
+	  /* #### Should we translate the months?  Or, even better, use
+	     ISO 8601 dates?  */
 	  static char *months[] = {
 	    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
 	    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
