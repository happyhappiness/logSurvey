 
       /* Is it big enough to match?  */
       if (len < pattern_prepercent_len + pattern_postpercent_len)
-	fail = 1;
+        fail = 1;
 
       /* Does the prefix match? */
       if (!fail && pattern_prepercent_len > 0
-	  && (*t != *pattern
-	      || t[pattern_prepercent_len - 1] != pattern_percent[-2]
-	      || !strneq (t + 1, pattern + 1, pattern_prepercent_len - 1)))
-	fail = 1;
+          && (*t != *pattern
+              || t[pattern_prepercent_len - 1] != pattern_percent[-2]
+              || !strneq (t + 1, pattern + 1, pattern_prepercent_len - 1)))
+        fail = 1;
 
       /* Does the suffix match? */
       if (!fail && pattern_postpercent_len > 0
-	  && (t[len - 1] != pattern_percent[pattern_postpercent_len - 1]
-	      || t[len - pattern_postpercent_len] != *pattern_percent
-	      || !strneq (&t[len - pattern_postpercent_len],
-			  pattern_percent, pattern_postpercent_len - 1)))
-	fail = 1;
+          && (t[len - 1] != pattern_percent[pattern_postpercent_len - 1]
+              || t[len - pattern_postpercent_len] != *pattern_percent
+              || !strneq (&t[len - pattern_postpercent_len],
+                          pattern_percent, pattern_postpercent_len - 1)))
+        fail = 1;
 
       if (fail)
-	/* It didn't match.  Output the string.  */
-	o = variable_buffer_output (o, t, len);
+        /* It didn't match.  Output the string.  */
+        o = variable_buffer_output (o, t, len);
       else
-	{
-	  /* It matched.  Output the replacement.  */
-
-	  /* Output the part of the replacement before the %.  */
-	  o = variable_buffer_output (o, replace, replace_prepercent_len);
-
-	  if (replace_percent != 0)
-	    {
-	      /* Output the part of the matched string that
-		 matched the % in the pattern.  */
-	      o = variable_buffer_output (o, t + pattern_prepercent_len,
-					  len - (pattern_prepercent_len
-						 + pattern_postpercent_len));
-	      /* Output the part of the replacement after the %.  */
-	      o = variable_buffer_output (o, replace_percent,
-					  replace_postpercent_len);
-	    }
-	}
+        {
+          /* It matched.  Output the replacement.  */
+
+          /* Output the part of the replacement before the %.  */
+          o = variable_buffer_output (o, replace, replace_prepercent_len);
+
+          if (replace_percent != 0)
+            {
+              /* Output the part of the matched string that
+                 matched the % in the pattern.  */
+              o = variable_buffer_output (o, t + pattern_prepercent_len,
+                                          len - (pattern_prepercent_len
+                                                 + pattern_postpercent_len));
+              /* Output the part of the replacement after the %.  */
+              o = variable_buffer_output (o, replace_percent,
+                                          replace_postpercent_len);
+            }
+        }
 
       /* Output a space, but not if the replacement is "".  */
       if (fail || replace_prepercent_len > 0
-	  || (replace_percent != 0 && len + replace_postpercent_len > 0))
-	{
-	  o = variable_buffer_output (o, " ", 1);
-	  doneany = 1;
-	}
+          || (replace_percent != 0 && len + replace_postpercent_len > 0))
+        {
+          o = variable_buffer_output (o, " ", 1);
+          doneany = 1;
+        }
     }
   if (doneany)
     /* Kill the last space.  */
