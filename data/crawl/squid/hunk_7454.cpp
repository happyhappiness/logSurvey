 {
     char **tmp = NULL;
     int i;
+    if (strlen(path) > (SQUID_MAXPATHLEN-32))
+	fatal_dump("cache_dir pathname is too long");
     if (CacheDirs == NULL) {
 	CacheDirsAllocated = 4;
 	CacheDirs = xcalloc(CacheDirsAllocated, sizeof(char *));
