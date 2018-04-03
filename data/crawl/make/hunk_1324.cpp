 	  /* Check for both : and :: rules.  Check is_target so
 	     we don't lose on default suffix rules or makefiles.  */
 	  if (f != 0 && f->is_target && !f->double_colon)
-	    makefile_fatal (filename, lineno,
+	    fatal (flocp,
 			    "target file `%s' has both : and :: entries",
 			    f->name);
 	  f = enter_file (name);
