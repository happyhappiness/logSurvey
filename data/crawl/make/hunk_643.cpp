         continue;
 
       /* Create the dependency list.
-         If we're not doing 2nd expansion, then it's just the name.  */
+         If we're not doing 2nd expansion, then it's just the name.  We will
+         still need to massage it though.  */
       if (! d->need_2nd_expansion)
-        p = d->name;
+        {
+          p = variable_expand ("");
+          variable_buffer_output (p, d->name, strlen (d->name) + 1);
+        }
       else
         {
           /* If it's from a static pattern rule, convert the patterns into
