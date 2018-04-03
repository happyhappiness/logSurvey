 			start_move(request);
 		} else {
 			fprintf(stderr,	"PUT %s failed, aborting (%d/%ld)\n",
-				sha1_to_hex(request->obj->sha1),
+				oid_to_hex(&request->obj->oid),
 				request->curl_result, request->http_code);
 			request->state = ABORTED;
 			aborted = 1;
