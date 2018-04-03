 	packfile = fopen(request->tmpfile, "a");
 	if (!packfile) {
 		fprintf(stderr, "Unable to open local file %s for pack",
-			filename);
+			request->tmpfile);
 		remote->can_update_info_refs = 0;
 		free(url);
 		return;
