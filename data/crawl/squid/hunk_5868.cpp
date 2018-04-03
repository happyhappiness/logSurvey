     if (l2 <= 0)
 	fatal("storeDiskdDirParse: invalid level 2 directories value");
     i = GetInteger();
-    magic1 = i;
-    if (magic1 <= 0)
-	fatal("storeDiskdDirParse: invalid magic1 value");
-    i = GetInteger();
-    magic2 = i;
-    if (magic2 <= 0)
-	fatal("storeDiskdDirParse: invalid magic2 value");
-
-
-    if ((token = strtok(NULL, w_space)))
-	if (!strcasecmp(token, "read-only"))
-	    read_only = 1;
 
     sd->fsdata = diskdinfo = xcalloc(1, sizeof(*diskdinfo));
     sd->index = index;
