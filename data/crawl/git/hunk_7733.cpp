 	indexfile = fopen(tmpfile, "a");
 	if (!indexfile)
 		return error("Unable to open local file %s for pack index",
-			     filename);
+			     tmpfile);
 
 	slot = get_active_slot();
 	slot->results = &results;
