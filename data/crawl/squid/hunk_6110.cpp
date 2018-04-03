     return s == NULL;
 }
 
-static void
-parse_cachedir(cacheSwap * swap)
+void
+allocate_new_swapdir(cacheSwap * swap)
 {
-    char *token;
-    char *path;
-    int i;
-    int size;
-    int l1;
-    int l2;
-    unsigned int read_only = 0;
-    SwapDir *tmp = NULL;
-    if ((path = strtok(NULL, w_space)) == NULL)
-	self_destruct();
-    GetInteger(i);
-    size = i << 10;		/* Mbytes to kbytes */
-    if (size <= 0)
-	fatal("parse_cachedir: invalid size value");
-    GetInteger(i);
-    l1 = i;
-    if (l1 <= 0)
-	fatal("parse_cachedir: invalid level 1 directories value");
-    GetInteger(i);
-    l2 = i;
-    if (l2 <= 0)
-	fatal("parse_cachedir: invalid level 2 directories value");
-    if ((token = strtok(NULL, w_space)))
-	if (!strcasecmp(token, "read-only"))
-	    read_only = 1;
-    for (i = 0; i < swap->n_configured; i++) {
-	tmp = swap->swapDirs + i;
-	if (!strcmp(path, tmp->path)) {
-	    /* just reconfigure it */
-	    if (size == tmp->max_size)
-		debug(3, 1) ("Cache dir '%s' size remains unchanged at %d KB\n",
-		    path, size);
-	    else
-		debug(3, 1) ("Cache dir '%s' size changed to %d KB\n",
-		    path, size);
-	    tmp->max_size = size;
-	    if (tmp->flags.read_only != read_only)
-		debug(3, 1) ("Cache dir '%s' now %s\n",
-		    path, read_only ? "Read-Only" : "Read-Write");
-	    tmp->flags.read_only = read_only;
-	    return;
-	}
-    }
     if (swap->swapDirs == NULL) {
 	swap->n_allocated = 4;
 	swap->swapDirs = xcalloc(swap->n_allocated, sizeof(SwapDir));
     }
     if (swap->n_allocated == swap->n_configured) {
+	SwapDir *tmp;
 	swap->n_allocated <<= 1;
 	tmp = xcalloc(swap->n_allocated, sizeof(SwapDir));
 	xmemcpy(tmp, swap->swapDirs, swap->n_configured * sizeof(SwapDir));
 	xfree(swap->swapDirs);
 	swap->swapDirs = tmp;
     }
-    tmp = swap->swapDirs + swap->n_configured;
-    tmp->path = xstrdup(path);
-    tmp->max_size = size;
-    tmp->l1 = l1;
-    tmp->l2 = l2;
-    tmp->flags.read_only = read_only;
-    tmp->swaplog_fd = -1;
-    swap->n_configured++;
+}
+
+static void
+parse_cachedir(cacheSwap * swap)
+{
+    char *type_str;
+    if ((type_str = strtok(NULL, w_space)) == NULL)
+	self_destruct();
+    if (0 == strcasecmp(type_str, "ufs")) {
+	storeUfsDirParse(swap);
+    } else {
+	fatalf("Unknown cache_dir type '%s'\n", type_str);
+    }
 }
 
 static void
