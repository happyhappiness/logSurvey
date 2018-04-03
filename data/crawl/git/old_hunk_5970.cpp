{
	struct object_request *entry = object_queue_head;

	if (obj_req->local != -1)
		error("fd leakage in release: %d", obj_req->local);
	if (obj_req == object_queue_head) {
		object_queue_head = obj_req->next;
	} else {
