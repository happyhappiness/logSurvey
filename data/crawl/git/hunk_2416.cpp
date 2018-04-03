 	if (request->state == RUN_MKCOL) {
 		if (request->curl_result == CURLE_OK ||
 		    request->http_code == 405) {
-			remote_dir_exists[get_object_hash(*request->obj)[0]] = 1;
+			remote_dir_exists[request->obj->oid.hash[0]] = 1;
 			start_put(request);
 		} else {
 			fprintf(stderr, "MKCOL %s failed, aborting (%d/%ld)\n",
