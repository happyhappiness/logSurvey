	struct walker_data *data = walker->data;

	snprintf(prevfile, sizeof(prevfile), "%s.prev", obj_req->filename);
	unlink(prevfile);
	rename(obj_req->tmpfile, prevfile);
	unlink(obj_req->tmpfile);

	if (obj_req->local != -1)
		error("fd leakage in start: %d", obj_req->local);
