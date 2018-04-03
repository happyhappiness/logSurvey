   var[namelen] = '\0';
   var = variable_expand (var);
 
-  initbuffer (&lb);
-  while (!feof (infile))
+  defstart = ebuf->floc;
+
+  while (1)
     {
       unsigned int len;
+      char *line;
 
-      flocp->lineno += nlines;
-      nlines = readline (&lb, infile, flocp);
+      ebuf->floc.lineno += nlines;
+      nlines = readline (ebuf);
 
-      collapse_continuations (lb.buffer);
+      /* If there is nothing left to eval, we're done. */
+      if (nlines < 0)
+        break;
 
-      p = next_token (lb.buffer);
-      len = strlen (p);
-      if ((len == 5 || (len > 5 && isblank ((unsigned char)p[5])))
-          && strneq (p, "endef", 5))
-	{
-	  p += 5;
-	  remove_comments (p);
-	  if (*next_token (p) != '\0')
-	    error (flocp, _("Extraneous text after `endef' directive"));
-	  /* Define the variable.  */
-	  if (idx == 0)
-	    definition[0] = '\0';
-	  else
-	    definition[idx - 1] = '\0';
-	  (void) define_variable_loc (var, strlen (var), definition, origin,
-                                      1, flocp);
-	  free (definition);
-	  freebuffer (&lb);
-	  return;
-	}
-      else
-	{
-          len = strlen (lb.buffer);
-	  /* Increase the buffer size if necessary.  */
-	  if (idx + len + 1 > length)
-	    {
-	      length = (idx + len) * 2;
-	      definition = (char *) xrealloc (definition, length + 1);
-	    }
+      line = ebuf->buffer;
 
-	  bcopy (lb.buffer, &definition[idx], len);
-	  idx += len;
-	  /* Separate lines with a newline.  */
-	  definition[idx++] = '\n';
-	}
+      collapse_continuations (line);
+
+      /* If the line doesn't begin with a tab, test to see if it introduces
+         another define, or ends one.  */
+
+      /* Stop if we find an 'endef' */
+      if (line[0] != '\t')
+        {
+          p = next_token (line);
+          len = strlen (p);
+
+          /* If this is another 'define', increment the level count.  */
+          if ((len == 6 || (len > 6 && isblank ((unsigned char)p[6])))
+              && strneq (p, "define", 6))
+            ++nlevels;
+
+          /* If this is an 'endef', decrement the count.  If it's now 0,
+             we've found the last one.  */
+          else if ((len == 5 || (len > 5 && isblank ((unsigned char)p[5])))
+                   && strneq (p, "endef", 5))
+            {
+              p += 5;
+              remove_comments (p);
+              if (*next_token (p) != '\0')
+                error (&ebuf->floc,
+                       _("Extraneous text after `endef' directive"));
+
+              if (--nlevels == 0)
+                {
+                  /* Define the variable.  */
+                  if (idx == 0)
+                    definition[0] = '\0';
+                  else
+                    definition[idx - 1] = '\0';
+
+                  /* Always define these variables in the global set.  */
+                  define_variable_global (var, strlen (var), definition,
+                                          origin, 1, &defstart);
+                  free (definition);
+                  return;
+                }
+            }
+        }
+
+      /* Otherwise add this line to the variable definition.  */
+      len = strlen (line);
+      if (idx + len + 1 > length)
+        {
+          length = (idx + len) * 2;
+          definition = (char *) xrealloc (definition, length + 1);
+        }
+
+      bcopy (line, &definition[idx], len);
+      idx += len;
+      /* Separate lines with a newline.  */
+      definition[idx++] = '\n';
     }
 
   /* No `endef'!!  */
-  fatal (flocp, _("missing `endef', unterminated `define'"));
+  fatal (&defstart, _("missing `endef', unterminated `define'"));
 
   /* NOTREACHED */
   return;
