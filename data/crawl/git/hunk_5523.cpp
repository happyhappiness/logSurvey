 
 	dir = directory;
 
-	if (avoid_alias(dir)) {
+	if (daemon_avoid_alias(dir)) {
 		logerror("'%s': aliased", dir);
 		return NULL;
 	}
