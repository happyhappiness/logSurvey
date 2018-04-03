 	  any_remote |= c->remote;
 	  any_local |= ! c->remote;
 	  if (debug_flag)
-	    printf ("Live child 0x%08lx (%s) PID %ld token %c%s\n",
+	    printf (_("Live child 0x%08lx (%s) PID %ld token %c%s\n"),
 		    (unsigned long int) c, c->file->name,
                     (long) c->pid, c->job_token,
-                    c->remote ? " (remote)" : "");
+                    c->remote ? _(" (remote)") : "");
 #ifdef VMS
 	  break;
 #endif
