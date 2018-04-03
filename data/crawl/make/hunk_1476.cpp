 		  && file->update_status == 0 && !g->changed
 		  /* Never give a message under -s or -q.  */
 		  && !silent_flag && !question_flag)
-		{
-		  if (file->phony || file->cmds == 0)
-		    message ("Nothing to be done for `%s'.",
-			     file->name);
-		  else
-		    message ("`%s' is up to date.", file->name);
-		  fflush (stdout);
-		}
+		message (1, ((file->phony || file->cmds == 0)
+			     ? "Nothing to be done for `%s'."
+			     : "`%s' is up to date."),
+			 file->name);
 
 	      /* This goal is finished.  Remove it from the chain.  */
 	      if (lastgoal == 0)
