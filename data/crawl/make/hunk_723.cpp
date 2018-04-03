 	}
       else
 	{
-	  /* Double-colon.  Make a new record
-	     even if the file already has one.  */
+	  /* Double-colon.  Make a new record even if there already is one.  */
 	  f = lookup_file (name);
+
 	  /* Check for both : and :: rules.  Check is_target so
 	     we don't lose on default suffix rules or makefiles.  */
 	  if (f != 0 && f->is_target && !f->double_colon)
 	    fatal (flocp,
                    _("target file `%s' has both : and :: entries"), f->name);
 	  f = enter_file (name);
-	  /* If there was an existing entry and it was a double-colon
-	     entry, enter_file will have returned a new one, making it the
-	     prev pointer of the old one, and setting its double_colon
-	     pointer to the first one.  */
+	  /* If there was an existing entry and it was a double-colon entry,
+	     enter_file will have returned a new one, making it the prev
+	     pointer of the old one, and setting its double_colon pointer to
+	     the first one.  */
 	  if (f->double_colon == 0)
-	    /* This is the first entry for this name, so we must
-	       set its double_colon pointer to itself.  */
+	    /* This is the first entry for this name, so we must set its
+	       double_colon pointer to itself.  */
 	    f->double_colon = f;
 	  f->is_target = 1;
 	  f->deps = this;
 	  f->cmds = cmds;
 	}
 
-      /* If this is a static pattern rule, set the file's stem to
-         the part of its name that matched the `%' in the pattern,
-         so you can use $* in the commands.  */
-      if (pattern != 0)
+      /* If this is a static pattern rule, set the stem to the part of its
+         name that matched the `%' in the pattern, so you can use $* in the
+         commands.  */
+      if (pattern)
         {
           static char *percent = "%";
           char *buffer = variable_expand ("");
           char *o = patsubst_expand (buffer, name, pattern, percent,
                                      pattern_percent+1, percent+1);
           f->stem = savestring (buffer, o - buffer);
+          if (this)
+            this->staticpattern = 1;
         }
 
       /* Free name if not needed further.  */
