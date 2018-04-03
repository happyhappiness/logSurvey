       return o;
     }
 
-  while ((p = sindex (t, 0, subst, slen)) != 0)
+  do
     {
+      if ((by_word | suffix_only) && slen == 0)
+	/* When matching by words, the empty string should match
+	   the end of each word, rather than the end of the whole text.  */
+	p = end_of_token (next_token (t));
+      else
+	{
+	  p = sindex (t, 0, subst, slen);
+	  if (p == 0)
+	    {
+	      /* No more matches.  Output everything left on the end.  */
+	      o = variable_buffer_output (o, t, strlen (t));
+	      return o;
+	    }
+	}
+
       /* Output everything before this occurrence of the string to replace.  */
       if (p > t)
 	o = variable_buffer_output (o, t, p - t);
