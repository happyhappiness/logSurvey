			aborted = 1;
		}
	} else if (request->state == RUN_FETCH_LOOSE) {
		obj_req = (struct http_object_request *)request->userData;

		if (finish_http_object_request(obj_req) == 0)
			if (obj_req->rename == 0)
				request->obj->flags |= (LOCAL | REMOTE);

		/* Try fetching packed if necessary */
		if (request->obj->flags & LOCAL) {
			release_http_object_request(obj_req);
			release_request(request);
		} else
			start_fetch_packed(request);

	} else if (request->state == RUN_FETCH_PACKED) {
