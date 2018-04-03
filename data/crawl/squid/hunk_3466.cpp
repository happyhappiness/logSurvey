 
     dlinkDelete(&srv->link, &hlp->servers);
 
-    hlp->n_running--;
-
-    assert(hlp->n_running >= 0);
+    assert(hlp->childs.n_running > 0);
+    hlp->childs.n_running--;
 
     if (!srv->flags.shutdown) {
-        hlp->n_active--;
-        assert( hlp->n_active >= 0);
+        assert( hlp->childs.n_active > 0);
+        hlp->childs.n_active--;
         debugs(84, 0, "WARNING: " << hlp->id_name << " #" << srv->index + 1 << " (FD " << fd << ") exited");
 
-        if (hlp->n_active <= hlp->n_to_start / 2) {
-            debugs(80, 0, "Too few " << hlp->id_name << " processes are running");
+        if (hlp->childs.needNew() > 0) {
+            debugs(80, 1, "Too few " << hlp->id_name << " processes are running (need " << hlp->childs.needNew() << "/" << hlp->childs.n_max << ")");
 
-            if (hlp->last_restart > squid_curtime - 30)
+            if (hlp->childs.n_active < hlp->childs.n_startup && hlp->last_restart > squid_curtime - 30)
                 fatalf("The %s helpers are crashing too rapidly, need help!\n", hlp->id_name);
 
-            debugs(80, 0, "Starting new helpers");
-
+            debugs(80, 1, "Starting new helpers");
             helperStatefulOpenServers(hlp);
         }
     }