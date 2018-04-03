 	char *hex = sha1_to_hex(sha1);
 	int ret = 0;
 	struct object_request *obj_req = object_queue_head;
+	struct http_object_request *req;
 
 	while (obj_req != NULL && hashcmp(obj_req->sha1, sha1))
 		obj_req = obj_req->next;
 	if (obj_req == NULL)
 		return error("Couldn't find request for %s in the queue", hex);
 
 	if (has_sha1_file(obj_req->sha1)) {
+		if (obj_req->req != NULL)
+			abort_http_object_request(obj_req->req);
 		abort_object_request(obj_req);
 		return 0;
 	}
