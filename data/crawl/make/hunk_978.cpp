     {
     case cs_running:
       c->next = children;
-      if (debug_flag)
-	printf (_("Putting child 0x%08lx (%s) PID %ld%s on the chain.\n"),
-		(unsigned long int) c, c->file->name,
-                (long) c->pid, c->remote ? _(" (remote)") : "");
+      DB (DB_JOBS, (_("Putting child 0x%08lx (%s) PID %ld%s on the chain.\n"),
+                    (unsigned long int) c, c->file->name,
+                    (long) c->pid, c->remote ? _(" (remote)") : ""));
       children = c;
       /* One more job slot is in use.  */
       ++job_slots_used;
