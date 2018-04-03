     if ((path_str = strtok(NULL, w_space)) == NULL)
         self_destruct();
 
-    /*
-     * This bit of code is a little strange.
-     * See, if we find a path and type match for a given line, then
-     * as long as we're reconfiguring, we can just call its reconfigure
-     * function. No harm there.
-     *
-     * Trouble is, if we find a path match, but not a type match, we have
-     * a dilemma - we could gracefully shut down the fs, kill it, and
-     * create a new one of a new type in its place, BUT at this stage the
-     * fs is meant to be the *NEW* one, and so things go very strange. :-)
-     *
-     * So, we'll assume the person isn't going to change the fs type for now,
-     * and XXX later on we will make sure that its picked up.
-     *
-     * (moving around cache_dir lines will be looked at later in a little
-     * more sane detail..)
-     */
 
-    for (i = 0; i < swap->n_configured; i++) {
-        assert (swap->swapDirs[i].getRaw());
+    fs = find_fstype(type_str);
 
-        /* this is specific to on-fs Stores. The right
-         * way to handle this is probably to have a mapping 
-         * from paths to stores, and have on-fs stores
-         * register with that, and lookip in that in their
-         * own setup logic. RBC 20041225. TODO.
-         */
+    if (fs < 0)
+        self_destruct();
 
-        if (0 == strcasecmp(path_str, dynamic_cast<SwapDir *>(swap->swapDirs[i].getRaw())->
-                            path)) {
-            /* existing configured swap dir */
-            /* This is a little weird, you'll appreciate it later */
-            fs = find_fstype(type_str);
+    /* reconfigure existing dir */
 
-            if (fs < 0) {
-                fatalf("Unknown cache_dir type '%s'\n", type_str);
-            }
+    for (i = 0; i < swap->n_configured; i++) {
+        assert (swap->swapDirs[i].getRaw());
 
-            /* TODO: warn here on type changing */
+        if ((strcasecmp(path_str, dynamic_cast<SwapDir *>(swap->swapDirs[i].getRaw())->path)
+            ) == 0) {
+            /* this is specific to on-fs Stores. The right
+             * way to handle this is probably to have a mapping 
+             * from paths to stores, and have on-fs stores
+             * register with that, and lookip in that in their
+             * own setup logic. RBC 20041225. TODO.
+             */
 
             sd = dynamic_cast<SwapDir *>(swap->swapDirs[i].getRaw());
 
+            if (sd->type() != StoreFileSystem::FileSystems().items[fs]->type()) {
+                debug(3, 0) ("ERROR: Can't change type of existing cache_dir %s %s to %s. Restart required\n", sd->type(), sd->path, type_str);
+                return;
+            }
+
             sd->reconfigure (i, path_str);
 
             update_maxobjsize();
