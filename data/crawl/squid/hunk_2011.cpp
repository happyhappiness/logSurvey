         if (hlp->childs.needNew() > 0) {
             debugs(80, DBG_IMPORTANT, "Too few " << hlp->id_name << " processes are running (need " << hlp->childs.needNew() << "/" << hlp->childs.n_max << ")");
 
-            if (hlp->childs.n_active < hlp->childs.n_startup && hlp->last_restart > squid_curtime - 30)
-                fatalf("The %s helpers are crashing too rapidly, need help!\n", hlp->id_name);
+            if (hlp->childs.n_active < hlp->childs.n_startup && hlp->last_restart > squid_curtime - 30) {
+                if (srv->stats.replies < 1)
+                    fatalf("The %s helpers are crashing too rapidly, need help!\n", hlp->id_name);
+                else
+                    debugs(80, DBG_CRITICAL, "ERROR: The " << hlp->id_name << " helpers are crashing too rapidly, need help!");
+            }
 
             debugs(80, DBG_IMPORTANT, "Starting new helpers");
             helperStatefulOpenServers(hlp);