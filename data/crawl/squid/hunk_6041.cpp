     }
 }
 
+static int
+find_fstype(char *type)
+{
+    int i;
+    for (i = 0; storefs_list[i].typestr != NULL; i++) {
+        if (strcasecmp(type, storefs_list[i].typestr) == 0) {
+	    return i;
+	}
+    }
+    return (-1);
+}
+
 static void
 parse_cachedir(cacheSwap * swap)
 {
     char *type_str;
+    char *path_str;
+    SwapDir *sd;
+    int i;
+    int fs;
+    size_t maxobjsize;
+
     if ((type_str = strtok(NULL, w_space)) == NULL)
 	self_destruct();
-    if (0 == strcasecmp(type_str, "ufs")) {
-	storeUfsDirParse(swap);
-#if USE_ASYNC_IO
-    } else if (0 == strcasecmp(type_str, "asyncufs")) {
-	storeAufsDirParse(swap);
-#endif
-#if USE_DISKD
-    } else if (0 == strcasecmp(type_str, "diskd")) {
-	storeDiskdDirParse(swap);
-#endif
-    } else {
-	fatalf("Unknown cache_dir type '%s'\n", type_str);
+
+    maxobjsize = (size_t)GetInteger();
+
+    if ((path_str = strtok(NULL, w_space)) == NULL)
+	self_destruct();
+
+    /*
+     * This bit of code is a little strange.
+     * See, if we find a path and type match for a given line, then
+     * as long as we're reconfiguring, we can just call its reconfigure
+     * function. No harm there.
+     *
+     * Trouble is, if we find a path match, but not a type match, we have
+     * a dilemma - we could gracefully shut down the fs, kill it, and
+     * create a new one of a new type in its place, BUT at this stage the
+     * fs is meant to be the *NEW* one, and so things go very strange. :-)
+     *
+     * So, we'll assume the person isn't going to change the fs type for now,
+     * and XXX later on we will make sure that its picked up.
+     *
+     * (moving around cache_dir lines will be looked at later in a little
+     * more sane detail..)
+     */
+
+    for (i = 0; i < swap->n_configured; i++) {
+        if (0 == strcasecmp(path_str, swap->swapDirs[i].path)) {
+	    /* This is a little weird, you'll appreciate it later */
+	    fs = find_fstype(type_str);
+	    if (fs < 0) {
+                fatalf("Unknown cache_dir type '%s'\n", type_str);
+	    }
+	    sd = swap->swapDirs + i;
+	    storefs_list[fs].reconfigurefunc(sd, i, path_str);
+            sd->max_objsize = maxobjsize;
+            update_maxobjsize();
+            return;
+	}
+    }
+
+    fs = find_fstype(type_str);
+    if (fs < 0) {
+        /* If we get here, we didn't find a matching cache_dir type */
+        fatalf("Unknown cache_dir type '%s'\n", type_str);
     }
+
+    allocate_new_swapdir(swap);
+    sd = swap->swapDirs + swap->n_configured;
+    storefs_list[fs].parsefunc(sd, swap->n_configured, path_str);
+    /* XXX should we dupe the string here, in case it gets trodden on? */
+    sd->type = storefs_list[fs].typestr;
+    sd->max_objsize = maxobjsize;
+    swap->n_configured++;
+    /* Update the max object size */
+    update_maxobjsize();
 }
 
 static void
