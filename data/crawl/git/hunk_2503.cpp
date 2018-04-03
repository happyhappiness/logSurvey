 			start_put(request);
 		} else {
 			fprintf(stderr, "MKCOL %s failed, aborting (%d/%ld)\n",
-				sha1_to_hex(request->obj->sha1),
+				oid_to_hex(&request->obj->oid),
 				request->curl_result, request->http_code);
 			request->state = ABORTED;
 			aborted = 1;
