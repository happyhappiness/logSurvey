       DBF (DB_VERBOSE, _("Giving up on target file '%s'.\n"));
 
       if (depth == 0 && keep_going_flag
-	  && !just_print_flag && !question_flag)
-	error (NILF,
+          && !just_print_flag && !question_flag)
+        error (NILF,
                _("Target '%s' not remade because of errors."), file->name);
 
       return dep_status;
