     magic2 = i;
     if (magic2 <= 0)
 	fatal("storeDiskdDirParse: invalid magic2 value");
-    if ((token = strtok(NULL, w_space)))
-	if (!strcasecmp(token, "read-only"))
-	    read_only = 1;
 
     /* just reconfigure it */
     if (size == sd->max_size)
