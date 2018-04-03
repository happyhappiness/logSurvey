 	free(theirs.ptr);
 	if (status < 0 || !result_buf.ptr) {
 		free(result_buf.ptr);
-		return error("path '%s': cannot merge", path);
+		return error(_("path '%s': cannot merge"), path);
 	}
 
 	/*
