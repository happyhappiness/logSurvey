 	  f = enter_file (name);
 
 	  if (f->double_colon)
-	    makefile_fatal (filename, lineno,
+	    fatal (flocp,
 			    "target file `%s' has both : and :: entries",
 			    f->name);
 
 	  /* If CMDS == F->CMDS, this target was listed in this rule
 	     more than once.  Just give a warning since this is harmless.  */
 	  if (cmds != 0 && cmds == f->cmds)
-	    makefile_error
-	      (filename, lineno,
+	    error
+	      (flocp,
 	       "target `%s' given more than once in the same rule.",
 	       f->name);
 
