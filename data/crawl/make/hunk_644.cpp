          plain prerequisite names.  */
       if (new && d->staticpattern)
         {
-          char *pattern = "%";
+          const char *pattern = "%";
           char *buffer = variable_expand ("");
           struct dep *dp = new, *dl = 0;
 
           while (dp != 0)
             {
-              char *percent = find_percent (dp->name);
+              char *percent;
+              int nl = strlen (dp->name) + 1;
+              char *nm = alloca (nl);
+              memcpy (nm, dp->name, nl);
+              percent = find_percent (nm);
               if (percent)
                 {
+                  char *o;
+
                   /* We have to handle empty stems specially, because that
                      would be equivalent to $(patsubst %,dp->name,) which
                      will always be empty.  */
                   if (d->stem[0] == '\0')
-                    /* This needs memmove() in ISO C.  */
-                    memmove (percent, percent+1, strlen (percent));
-                  else
                     {
-                      char *o = patsubst_expand (buffer, d->stem, pattern,
-                                                 dp->name, pattern+1,
-                                                 percent+1);
-                      if (o == buffer)
-                        dp->name[0] = '\0';
-                      else
-                        {
-                          free (dp->name);
-                          dp->name = savestring (buffer, o - buffer);
-                        }
+                      memmove (percent, percent+1, strlen (percent));
+                      o = variable_buffer_output (buffer, nm, strlen (nm) + 1);
                     }
+                  else
+                    o = patsubst_expand_pat (buffer, d->stem, pattern, nm,
+                                             pattern+1, percent+1);
 
                   /* If the name expanded to the empty string, ignore it.  */
-                  if (dp->name[0] == '\0')
+                  if (buffer[0] == '\0')
                     {
                       struct dep *df = dp;
                       if (dp == new)
                         dp = new = new->next;
                       else
                         dp = dl->next = dp->next;
-                      /* @@ Are we leaking df->name here?  */
-                      df->name = 0;
                       free_dep (df);
                       continue;
                     }
+
+                  /* Save the name.  */
+                  dp->name = strcache_add_len (buffer, o - buffer);
                 }
               dl = dp;
               dp = dp->next;
