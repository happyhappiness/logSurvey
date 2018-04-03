 	}
     }
 
-  /* For a top level target, if we have found nothing whatever to do for it,
-     print a message saying nothing needs doing.  */
-
-  /* Give a message iff updated successfully, and never under -s or -q.  */
-  if (status == 0 && !silent_flag && !question_flag
-      /* files_remade will have been incremented iff we actually
-	 ran any commands (under -n, if we would have).  */
-      && files_remade == ofiles_remade
-      /* Only give the diagnostic for top-level targets.
-	 The makefile chain run is done with DEPTH==1 precisely
-	 to avoid this message.  */
-      && depth == 0)
-    {
-      if (file->phony || file->cmds == 0)
-	message ("Nothing to be done for `%s'.", file->name);
-      else
-	message ("`%s' is up to date.", file->name);
-      fflush (stdout);
-    }
-
   return status;
 }
 
