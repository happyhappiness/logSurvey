     l2 = i;
     if (l2 <= 0)
 	fatal("storeAufsDirReconfigure: invalid level 2 directories value");
-    if ((token = strtok(NULL, w_space)))
-	if (!strcasecmp(token, "read-only"))
-	    read_only = 1;
 
     /* just reconfigure it */
     if (size == sd->max_size)
