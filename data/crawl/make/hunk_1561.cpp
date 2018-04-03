 		    }
 		}
 
-	      g->file = g->file->prev;
-	      if (stop || g->file == 0)
+	      if (stop)
 		{
+		  /* If we have found nothing whatever to do for the goal,
+		     print a message saying nothing needs doing.  */
+
+		  /* If the update_status is zero, we updated successfully
+		     or not at all.  G->changed will have been set above if
+		     any commands were actually run on behalf of this goal.  */
+		  if (g->file->update_status == 0 && !g->changed
+		      /* Never give a message under -s or -q.  */
+		      && !silent_flag && !question_flag)
+		    {
+		      if (g->file->phony || g->file->cmds == 0)
+			message ("Nothing to be done for `%s'.",
+				 g->file->name);
+		      else
+			message ("`%s' is up to date.", g->file->name);
+		      fflush (stdout);
+		    }
+
 		  /* This goal is finished.  Remove it from the chain.  */
 		  if (lastgoal == 0)
 		    goals = g->next;
