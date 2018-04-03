                 print a message saying nothing needs doing.  */

              if (!rebuilding_makefiles
                  /* If the update_status is zero, we updated successfully
                     or not at all.  G->changed will have been set above if
                     any commands were actually started for this goal.  */
                  && file->update_status == 0 && !g->changed
                  /* Never give a message under -s or -q.  */
                  && !silent_flag && !question_flag)
                message (1, ((file->phony || file->cmds == 0)
