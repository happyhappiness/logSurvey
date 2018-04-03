 	struct walker_data *data = walker->data;
 
 	snprintf(prevfile, sizeof(prevfile), "%s.prev", obj_req->filename);
-	unlink(prevfile);
+	unlink_or_warn(prevfile);
 	rename(obj_req->tmpfile, prevfile);
-	unlink(obj_req->tmpfile);
+	unlink_or_warn(obj_req->tmpfile);
 
 	if (obj_req->local != -1)
 		error("fd leakage in start: %d", obj_req->local);
