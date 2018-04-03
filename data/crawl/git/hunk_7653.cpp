 	if (start_active_slot(slot)) {
 		run_active_slot(slot);
 		if (results.curl_result != CURLE_OK) {
+			strbuf_release(&buffer);
 			if (missing_target(&results)) {
 				repo->got_indices = 1;
-				free(buffer.buffer);
 				return 0;
 			} else {
 				repo->got_indices = 0;
-				free(buffer.buffer);
 				return error("%s", curl_errorstr);
 			}
 		}
 	} else {
 		repo->got_indices = 0;
-		free(buffer.buffer);
+		strbuf_release(&buffer);
 		return error("Unable to start request");
 	}
 
-	data = buffer.buffer;
-	while (i < buffer.posn) {
+	data = buffer.buf;
+	while (i < buffer.len) {
 		switch (data[i]) {
 		case 'P':
 			i++;
-			if (i + 52 <= buffer.posn &&
+			if (i + 52 <= buffer.len &&
 			    !prefixcmp(data + i, " pack-") &&
 			    !prefixcmp(data + i + 46, ".pack\n")) {
 				get_sha1_hex(data + i + 6, sha1);
