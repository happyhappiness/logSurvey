 			start_fetch_packed(request);
 
 	} else if (request->state == RUN_FETCH_PACKED) {
+		int fail = 1;
 		if (request->curl_result != CURLE_OK) {
 			fprintf(stderr, "Unable to get pack file %s\n%s",
 				request->url, curl_errorstr);
-			repo->can_update_info_refs = 0;
 		} else {
-			off_t pack_size = ftell(request->local_stream);
-
-			fclose(request->local_stream);
-			request->local_stream = NULL;
-			slot->local = NULL;
-			if (!move_temp_to_file(request->tmpfile,
-					       request->filename)) {
-				target = (struct packed_git *)request->userData;
-				target->pack_size = pack_size;
-				lst = &repo->packs;
-				while (*lst != target)
-					lst = &((*lst)->next);
-				*lst = (*lst)->next;
-
-				if (!verify_pack(target))
-					install_packed_git(target);
-				else
-					repo->can_update_info_refs = 0;
+			preq = (struct http_pack_request *)request->userData;
+
+			if (preq) {
+				if (finish_http_pack_request(preq) > 0)
+					fail = 0;
+				release_http_pack_request(preq);
 			}
 		}
+		if (fail)
+			repo->can_update_info_refs = 0;
 		release_request(request);
 	}
 }
