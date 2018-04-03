 
 	  if (f->double_colon)
 	    fatal (flocp,
-                   "target file `%s' has both : and :: entries", f->name);
+                   _("target file `%s' has both : and :: entries"), f->name);
 
 	  /* If CMDS == F->CMDS, this target was listed in this rule
 	     more than once.  Just give a warning since this is harmless.  */
 	  if (cmds != 0 && cmds == f->cmds)
-	    error (flocp, "target `%s' given more than once in the same rule.",
+	    error (flocp, _("target `%s' given more than once in the same rule."),
                    f->name);
 
 	  /* Check for two single-colon entries both with commands.