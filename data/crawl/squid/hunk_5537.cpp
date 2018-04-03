     if (l2 <= 0)
 	fatal("storeAufsDirParse: invalid level 2 directories value");
 
-    aioinfo = xmalloc(sizeof(squidaioinfo_t));
+    aioinfo = xmalloc(sizeof(squidufsinfo_t));
     if (aioinfo == NULL)
-	fatal("storeAufsDirParse: couldn't xmalloc() squidaioinfo_t!\n");
+	fatal("storeAufsDirParse: couldn't xmalloc() squidufsinfo_t!\n");
 
     sd->index = index;
     sd->path = xstrdup(path);
