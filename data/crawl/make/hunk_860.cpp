 		  p = strchr (p2, '\0');
 		  while (isblank ((unsigned char)p[-1]))
 		    --p;
-		  do_define (p2, p - p2, o_override, infile, &fileinfo);
+		  do_define (p2, p - p2, o_override, ebuf);
 		}
 	    }
 	  else if (!ignoring
-		   && !try_variable_definition (&fileinfo, p2, o_override, 0))
-	    error (&fileinfo, _("invalid `override' directive"));
+		   && !try_variable_definition (fstart, p2, o_override, 0))
+	    error (fstart, _("invalid `override' directive"));
 
 	  continue;
 	}
- skip_conditionals:
 
       if (ignoring)
 	/* Ignore the line.  We continue here so conditionals
 	   can appear in the middle of a rule.  */
 	continue;
 
-      if (!reading_target && word1eq ("export", 6))
+      if (word1eq ("export"))
 	{
-	  struct variable *v;
-	  p2 = next_token (p + 6);
+          /* 'export' by itself causes everything to be exported. */
 	  if (*p2 == '\0')
-	    export_all_variables = 1;
-	  v = try_variable_definition (&fileinfo, p2, o_file, 0);
-	  if (v != 0)
-	    v->export = v_export;
-	  else
-	    {
-	      unsigned int len;
-	      for (p = find_next_token (&p2, &len); p != 0;
-		   p = find_next_token (&p2, &len))
-		{
-		  v = lookup_variable (p, len);
-		  if (v == 0)
-		    v = define_variable_loc (p, len, "", o_file, 0, &fileinfo);
-		  v->export = v_export;
-		}
-	    }
+            export_all_variables = 1;
+          else
+            {
+              struct variable *v;
+
+              v = try_variable_definition (fstart, p2, o_file, 0);
+              if (v != 0)
+                v->export = v_export;
+              else
+                {
+                  unsigned int len;
+                  for (p = find_next_token (&p2, &len); p != 0;
+                       p = find_next_token (&p2, &len))
+                    {
+                      v = lookup_variable (p, len);
+                      if (v == 0)
+                        v = define_variable_loc (p, len, "", o_file, 0,
+                                                 fstart);
+                      v->export = v_export;
+                    }
+                }
+            }
+          goto rule_complete;
 	}
-      else if (!reading_target && word1eq ("unexport", 8))
+
+      if (word1eq ("unexport"))
 	{
-	  unsigned int len;
-	  struct variable *v;
-	  p2 = next_token (p + 8);
 	  if (*p2 == '\0')
 	    export_all_variables = 0;
-	  for (p = find_next_token (&p2, &len); p != 0;
-	       p = find_next_token (&p2, &len))
-	    {
-	      v = lookup_variable (p, len);
-	      if (v == 0)
-		v = define_variable_loc (p, len, "", o_file, 0, &fileinfo);
-	      v->export = v_noexport;
-	    }
+          else
+            {
+              unsigned int len;
+              struct variable *v;
+              for (p = find_next_token (&p2, &len); p != 0;
+                   p = find_next_token (&p2, &len))
+                {
+                  v = lookup_variable (p, len);
+                  if (v == 0)
+                    v = define_variable_loc (p, len, "", o_file, 0, fstart);
+                  v->export = v_noexport;
+                }
+            }
+          goto rule_complete;
 	}
-      else if (word1eq ("vpath", 5))
+
+ skip_conditionals:
+      if (word1eq ("vpath"))
 	{
 	  char *pattern;
 	  unsigned int len;
-	  p2 = variable_expand (p + 5);
+	  p2 = variable_expand (p2);
 	  p = find_next_token (&p2, &len);
 	  if (p != 0)
 	    {
