               set_command_state (file, cs_not_started);
             }
 
-	  ld = 0;
-	  d = file->deps;
-	  while (d != 0)
-	    {
+          ld = 0;
+          d = file->deps;
+          while (d != 0)
+            {
               int maybe_make;
 
-	      if (is_updating (d->file))
-		{
-		  error (NILF, _("Circular %s <- %s dependency dropped."),
-			 file->name, d->file->name);
-		  if (ld == 0)
-		    {
-		      file->deps = d->next;
+              if (is_updating (d->file))
+                {
+                  error (NILF, _("Circular %s <- %s dependency dropped."),
+                         file->name, d->file->name);
+                  if (ld == 0)
+                    {
+                      file->deps = d->next;
                       free_dep (d);
-		      d = file->deps;
-		    }
-		  else
-		    {
-		      ld->next = d->next;
+                      d = file->deps;
+                    }
+                  else
+                    {
+                      ld->next = d->next;
                       free_dep (d);
-		      d = ld->next;
-		    }
-		  continue;
-		}
+                      d = ld->next;
+                    }
+                  continue;
+                }
 
-	      d->file->parent = file;
+              d->file->parent = file;
               maybe_make = *must_make_ptr;
-	      dep_status |= check_dep (d->file, depth, this_mtime,
+              dep_status |= check_dep (d->file, depth, this_mtime,
                                        &maybe_make);
               if (! d->ignore_mtime)
                 *must_make_ptr = maybe_make;
-	      check_renamed (d->file);
-	      if (dep_status != 0 && !keep_going_flag)
-		break;
+              check_renamed (d->file);
+              if (dep_status != 0 && !keep_going_flag)
+                break;
 
-	      if (d->file->command_state == cs_running
-		  || d->file->command_state == cs_deps_running)
-		deps_running = 1;
+              if (d->file->command_state == cs_running
+                  || d->file->command_state == cs_deps_running)
+                deps_running = 1;
 
-	      ld = d;
-	      d = d->next;
-	    }
+              ld = d;
+              d = d->next;
+            }
 
           if (deps_running)
             /* Record that some of FILE's deps are still being made.
                This tells the upper levels to wait on processing it until the
                commands are finished.  */
             set_command_state (file, cs_deps_running);
-	}
+        }
     }
 
   finish_updating (file);
