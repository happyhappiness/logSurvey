   c->command_line = 0;
   c->command_ptr = 0;
   c->environment = 0;
-  start_job (c);
-  switch (file->command_state)
-    {
-    case cs_not_running:
-      /* The child is waiting to run.
-	 It has already been put on the `waiting_jobs' chain.  */
-      break;
-
-    case cs_running:
-      c->next = children;
-      if (debug_flag)
-	printf ("Putting child 0x%08lx PID %05d%s on the chain.\n",
-		(unsigned long int) c,
-		c->pid, c->remote ? " (remote)" : "");
-      children = c;
-      /* One more job slot is in use.  */
-      ++job_slots_used;
-      unblock_sigs ();
-      break;
-
-    case cs_finished:
-      free_child (c);
-      notice_finished_file (file);
-      break;
 
-    default:
-      error ("internal error: `%s' command_state == %d in new_job",
-	     file->name, (int) file->command_state);
-      abort ();
-      break;
-    }
+  start_waiting_job (c);
 
   if (job_slots == 1)
     /* Since there is only one job slot, make things run linearly.
