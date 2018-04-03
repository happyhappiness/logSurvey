 	  {
 	    /* Give a warning if there is no pattern, then remove the
 	       pattern so it's ignored next time.  */
-	    error (NILF, ".LIBPATTERNS element `%s' is not a pattern", p);
+	    error (NILF, _(".LIBPATTERNS element `%s' is not a pattern"), p);
 	    for (; len; --len, ++p)
 	      *p = ' ';
 	    *p = c;
