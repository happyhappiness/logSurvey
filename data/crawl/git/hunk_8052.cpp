 				    obj_req->errorstr, obj_req->curl_result,
 				    obj_req->http_code, hex);
 	} else if (obj_req->zret != Z_STREAM_END) {
-		corrupt_object_found++;
+		walker->corrupt_object_found++;
 		ret = error("File %s (%s) corrupt", hex, obj_req->url);
 	} else if (hashcmp(obj_req->sha1, obj_req->real_sha1)) {
 		ret = error("File %s has bad hash", hex);
