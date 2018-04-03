 	pos = cache_name_pos(filename, namelen);
 	if (pos < 0)
 		pos = -pos - 1;
-	ce = active_cache[pos];
-	if (ce_namelen(ce) == namelen &&
-	    !memcmp(ce->name, filename, namelen))
-		die("Path '%s' is in the index, but not at stage %d.\n"
-		    "Did you mean ':%d:%s'?",
-		    filename, stage,
-		    ce_stage(ce), filename);
+	if (pos < active_nr) {
+		ce = active_cache[pos];
+		if (ce_namelen(ce) == namelen &&
+		    !memcmp(ce->name, filename, namelen))
+			die("Path '%s' is in the index, but not at stage %d.\n"
+			    "Did you mean ':%d:%s'?",
+			    filename, stage,
+			    ce_stage(ce), filename);
+	}
 
 	/* Confusion between relative and absolute filenames? */
 	fullnamelen = namelen + strlen(prefix);
