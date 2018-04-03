
static struct object_request *object_queue_head;

static void fetch_alternates(struct walker *walker, const char *base);

static void process_object_response(void *callback_data);

static void start_object_request(struct walker *walker,
				 struct object_request *obj_req)
{
	struct active_request_slot *slot;
	struct http_object_request *req;

	req = new_http_object_request(obj_req->repo->base, obj_req->sha1);
	if (req == NULL) {
		obj_req->state = ABORTED;
		return;
	}
	obj_req->req = req;

	slot = req->slot;
	slot->callback_func = process_object_response;
	slot->callback_data = obj_req;

	/* Try to get the request started, abort the request on error */
	obj_req->state = ACTIVE;
	if (!start_active_slot(slot)) {
		obj_req->state = ABORTED;
		release_http_object_request(req);
		return;
	}
}

static void finish_object_request(struct object_request *obj_req)
{
	if (finish_http_object_request(obj_req->req))
		return;

	if (obj_req->req->rename == 0)
		walker_say(obj_req->walker, "got %s\n", sha1_to_hex(obj_req->sha1));
}
