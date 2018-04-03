 	  any_remote |= c->remote;
 	  any_local |= ! c->remote;
 	  if (debug_flag)
-	    printf ("Live child 0x%08lx PID %ld%s\n",
-		    (unsigned long int) c,
-		    (long) c->pid, c->remote ? " (remote)" : "");
+	    printf ("Live child 0x%08lx (%s) PID %ld token %c%s\n",
+		    (unsigned long int) c, c->file->name,
+                    (long) c->pid, c->job_token,
+                    c->remote ? " (remote)" : "");
 #ifdef VMS
 	  break;
 #endif
