 	if (start_active_slot(slot)) {
 		run_active_slot(slot);
 		if (results.curl_result != CURLE_OK) {
-			strbuf_release(&buffer);
 			if (missing_target(&results)) {
 				repo->got_indices = 1;
-				return 0;
+				goto cleanup;
 			} else {
 				repo->got_indices = 0;
-				return error("%s", curl_errorstr);
+				ret = error("%s", curl_errorstr);
+				goto cleanup;
 			}
 		}
 	} else {
 		repo->got_indices = 0;
-		strbuf_release(&buffer);
-		return error("Unable to start request");
+		ret = error("Unable to start request");
+		goto cleanup;
 	}
 
 	data = buffer.buf;
