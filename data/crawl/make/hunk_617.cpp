       collapse_continuations (collapsed);
       remove_comments (collapsed);
 
-      /* Compare a word, both length and contents. */
-#define	word1eq(s)	(wlen == sizeof(s)-1 && strneq (s, p, sizeof(s)-1))
-      p = collapsed;
-      while (isspace ((unsigned char)*p))
-	++p;
+      /* See if this is a variable assignment.  We need to do this early, to
+         allow variables with names like 'ifdef', 'export', 'private', etc.  */
+      p = parse_var_assignment(collapsed, &vmod);
+      if (vmod.assign_v)
+        {
+          struct variable *v;
+          enum variable_origin origin = vmod.override_v ? o_override : o_file;
 
-      if (*p == '\0')
-	/* This line is completely empty--ignore it.  */
-	continue;
+          /* If we're ignoring then we're done now.  */
+	  if (ignoring)
+            {
+              if (vmod.define_v)
+                in_ignored_define = 1;
+              continue;
+            }
 
-      /* Find the end of the first token.  Note we don't need to worry about
-       * ":" here since we compare tokens by length (so "export" will never
-       * be equal to "export:").
-       */
-      for (p2 = p+1; *p2 != '\0' && !isspace ((unsigned char)*p2); ++p2)
-        ;
-      wlen = p2 - p;
+          /* If it's a multi-line define / endef, manage that.  */
+          if (vmod.define_v)
+            {
+              if (*p == '\0')
+                fatal (fstart, _("empty variable name"));
 
-      /* Find the start of the second token.  If it looks like a target or
-         variable definition it can't be a preprocessor token so skip
-         them--this allows variables/targets named `ifdef', `export', etc. */
-      while (isspace ((unsigned char)*p2))
-        ++p2;
+              /* Let the variable name be the whole rest of the line,
+                 with trailing blanks stripped (comments have already been
+                 removed), so it could be a complex variable/function
+                 reference that might contain blanks.  */
+              p2 = p + strlen (p);
+              while (isblank ((unsigned char)p2[-1]))
+                --p2;
+              v = do_define (p, p2 - p, origin, ebuf);
+            }
+          else
+            {
+              v = try_variable_definition (fstart, p, origin, 0);
+              assert (v != NULL);
+            }
 
-      if ((p2[0] == ':' || p2[0] == '+' || p2[0] == '=') && p2[1] == '\0')
-        {
-          /* It can't be a preprocessor token so skip it if we're ignoring */
-          if (ignoring)
-            continue;
+          if (vmod.export_v)
+            v->export = v_export;
+          if (vmod.private_v)
+            v->private_var = 1;
 
-          goto skip_conditionals;
+          /* This line has been dealt with.  */
+          goto rule_complete;
         }
 
-      /* We must first check for conditional and `define' directives before
-	 ignoring anything, since they control what we will do with
-	 following lines.  */
-
-      if (!in_ignored_define)
-	{
-	  int i = conditional_line (p, wlen, fstart);
-          if (i != -2)
-            {
-              if (i == -1)
-                fatal (fstart, _("invalid syntax in conditional"));
-
-              ignoring = i;
-              continue;
-            }
-	}
+      /* If this line is completely empty, ignore it.  */
+      if (*p == '\0')
+	continue;
 
-      if (word1eq ("endef"))
-	{
-	  if (!in_ignored_define)
-	    fatal (fstart, _("extraneous `endef'"));
-          in_ignored_define = 0;
-	  continue;
-	}
+      p2 = end_of_token (p);
+      wlen = p2 - p;
+      p2 = next_token (p2);
 
-      if (word1eq ("define"))
+      /* If we're in an ignored define, skip this line (but maybe get out).  */
+      if (in_ignored_define)
 	{
-	  if (ignoring)
-	    in_ignored_define = 1;
-	  else
-	    {
-              if (*p2 == '\0')
-                fatal (fstart, _("empty variable name"));
+          /* See if this is an endef line (plus optional comment).  */
+          if (word1eq ("endef") && (*p2 == '\0' || *p2 == '#'))
+            in_ignored_define = 0;
 
-	      /* Let the variable name be the whole rest of the line,
-		 with trailing blanks stripped (comments have already been
-		 removed), so it could be a complex variable/function
-		 reference that might contain blanks.  */
-	      p = strchr (p2, '\0');
-	      while (isblank ((unsigned char)p[-1]))
-		--p;
-	      do_define (p2, p - p2, o_file, ebuf);
-	    }
 	  continue;
 	}
 
-      if (word1eq ("override"))
-        {
-	  if (*p2 == '\0')
-	    error (fstart, _("empty `override' directive"));
-
-	  if (strneq (p2, "define", 6)
-	      && (isblank ((unsigned char)p2[6]) || p2[6] == '\0'))
-	    {
-	      if (ignoring)
-		in_ignored_define = 1;
-	      else
-		{
-		  p2 = next_token (p2 + 6);
-                  if (*p2 == '\0')
-                    fatal (fstart, _("empty variable name"));
-
-		  /* Let the variable name be the whole rest of the line,
-		     with trailing blanks stripped (comments have already been
-		     removed), so it could be a complex variable/function
-		     reference that might contain blanks.  */
-		  p = strchr (p2, '\0');
-		  while (isblank ((unsigned char)p[-1]))
-		    --p;
-		  do_define (p2, p - p2, o_override, ebuf);
-		}
-	    }
-	  else if (!ignoring
-		   && !try_variable_definition (fstart, p2, o_override, 0))
-	    error (fstart, _("invalid `override' directive"));
+      /* Check for conditional state changes.  */
+      {
+        int i = conditional_line (p, wlen, fstart);
+        if (i != -2)
+          {
+            if (i == -1)
+              fatal (fstart, _("invalid syntax in conditional"));
 
-	  continue;
-	}
+            ignoring = i;
+            continue;
+          }
+      }
 
+      /* Nothing to see here... move along.  */
       if (ignoring)
-	/* Ignore the line.  We continue here so conditionals
-	   can appear in the middle of a rule.  */
 	continue;
 
-      if (word1eq ("export"))
+      /* Manage the "export" keyword used outside of variable assignment
+         as well as "unexport".  */
+      if (word1eq ("export") || word1eq ("unexport"))
 	{
-          /* 'export' by itself causes everything to be exported. */
-	  if (*p2 == '\0')
-            export_all_variables = 1;
-          else
-            {
-              struct variable *v;
-
-              v = try_variable_definition (fstart, p2, o_file, 0);
-              if (v != 0)
-                v->export = v_export;
-              else
-                {
-                  unsigned int l;
-                  const char *cp;
-                  char *ap;
-
-                  /* Expand the line so we can use indirect and constructed
-                     variable names in an export command.  */
-                  cp = ap = allocated_variable_expand (p2);
-
-                  for (p = find_next_token (&cp, &l); p != 0;
-                       p = find_next_token (&cp, &l))
-                    {
-                      v = lookup_variable (p, l);
-                      if (v == 0)
-                        v = define_variable_loc (p, l, "", o_file, 0, fstart);
-                      v->export = v_export;
-                    }
-
-                  free (ap);
-                }
-            }
-          goto rule_complete;
-	}
+          int exporting = *p == 'u' ? 0 : 1;
 
-      if (word1eq ("unexport"))
-	{
+          /* (un)export by itself causes everything to be (un)exported. */
 	  if (*p2 == '\0')
-	    export_all_variables = 0;
+            export_all_variables = exporting;
           else
             {
               unsigned int l;
-              struct variable *v;
               const char *cp;
               char *ap;
 
               /* Expand the line so we can use indirect and constructed
-                 variable names in an unexport command.  */
+                 variable names in an (un)export command.  */
               cp = ap = allocated_variable_expand (p2);
 
               for (p = find_next_token (&cp, &l); p != 0;
                    p = find_next_token (&cp, &l))
                 {
-                  v = lookup_variable (p, l);
+                  struct variable *v = lookup_variable (p, l);
                   if (v == 0)
                     v = define_variable_loc (p, l, "", o_file, 0, fstart);
-
-                  v->export = v_noexport;
+                  v->export = exporting ? v_export : v_noexport;
                 }
 
               free (ap);
