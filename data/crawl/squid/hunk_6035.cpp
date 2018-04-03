 
     diskdinfo = xmalloc(sizeof(diskdinfo_t));
     if (diskdinfo == NULL)
-        fatal("storeDiskdDirParse: couldn't xmalloc() diskdinfo_t!\n");
+	fatal("storeDiskdDirParse: couldn't xmalloc() diskdinfo_t!\n");
 
     sd->index = index;
     sd->path = xstrdup(path);
