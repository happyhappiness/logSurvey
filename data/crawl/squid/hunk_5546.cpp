     if (l2 <= 0)
 	fatal("storeUfsDirParse: invalid level 2 directories value");
 
-    ufsinfo = xmalloc(sizeof(ufsinfo_t));
+    ufsinfo = xmalloc(sizeof(squidufsinfo_t));
     if (ufsinfo == NULL)
-	fatal("storeUfsDirParse: couldn't xmalloc() ufsinfo_t!\n");
+	fatal("storeUfsDirParse: couldn't xmalloc() squidufsinfo_t!\n");
 
     sd->index = index;
     sd->path = xstrdup(path);
