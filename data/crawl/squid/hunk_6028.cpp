 
     aioinfo = xmalloc(sizeof(aioinfo_t));
     if (aioinfo == NULL)
-        fatal("storeAufsDirParse: couldn't xmalloc() aioinfo_t!\n");
+	fatal("storeAufsDirParse: couldn't xmalloc() aioinfo_t!\n");
 
     sd->index = index;
     sd->path = xstrdup(path);
