                     }
                 }
 
-	      /* Keep track if any double-colon entry is not finished.
+              /* Keep track if any double-colon entry is not finished.
                  When they are all finished, the goal is finished.  */
-	      any_not_updated |= !file->updated;
+              any_not_updated |= !file->updated;
 
               file->dontcare = 0;
 
-	      if (stop)
-		break;
-	    }
-
-	  /* Reset FILE since it is null at the end of the loop.  */
-	  file = g->file;
-
-	  if (stop || !any_not_updated)
-	    {
-	      /* If we have found nothing whatever to do for the goal,
-		 print a message saying nothing needs doing.  */
-
-	      if (!rebuilding_makefiles
-		  /* If the update_status is zero, we updated successfully
-		     or not at all.  G->changed will have been set above if
-		     any commands were actually started for this goal.  */
-		  && file->update_status == 0 && !g->changed
-		  /* Never give a message under -s or -q.  */
-		  && !silent_flag && !question_flag)
-		message (1, ((file->phony || file->cmds == 0)
-			     ? _("Nothing to be done for '%s'.")
-			     : _("'%s' is up to date.")),
-			 file->name);
-
-	      /* This goal is finished.  Remove it from the chain.  */
-	      if (lastgoal == 0)
-		goals = g->next;
-	      else
-		lastgoal->next = g->next;
-
-	      /* Free the storage.  */
-	      free (g);
-
-	      g = lastgoal == 0 ? goals : lastgoal->next;
-
-	      if (stop)
-		break;
-	    }
-	  else
-	    {
-	      lastgoal = g;
-	      g = g->next;
-	    }
-	}
+              if (stop)
+                break;
+            }
+
+          /* Reset FILE since it is null at the end of the loop.  */
+          file = g->file;
+
+          if (stop || !any_not_updated)
+            {
+              /* If we have found nothing whatever to do for the goal,
+                 print a message saying nothing needs doing.  */
+
+              if (!rebuilding_makefiles
+                  /* If the update_status is zero, we updated successfully
+                     or not at all.  G->changed will have been set above if
+                     any commands were actually started for this goal.  */
+                  && file->update_status == 0 && !g->changed
+                  /* Never give a message under -s or -q.  */
+                  && !silent_flag && !question_flag)
+                message (1, ((file->phony || file->cmds == 0)
+                             ? _("Nothing to be done for '%s'.")
+                             : _("'%s' is up to date.")),
+                         file->name);
+
+              /* This goal is finished.  Remove it from the chain.  */
+              if (lastgoal == 0)
+                goals = g->next;
+              else
+                lastgoal->next = g->next;
+
+              /* Free the storage.  */
+              free (g);
+
+              g = lastgoal == 0 ? goals : lastgoal->next;
+
+              if (stop)
+                break;
+            }
+          else
+            {
+              lastgoal = g;
+              g = g->next;
+            }
+        }
 
       /* If we reached the end of the dependency graph toggle the considered
          flag for the next pass.  */
