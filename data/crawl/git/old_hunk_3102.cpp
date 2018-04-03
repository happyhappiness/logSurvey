		die("Unhandled message id: %s", msg_id);
	type = parse_msg_type(msg_type);

	if (!options->msg_type) {
		int i;
		int *msg_type = xmalloc(sizeof(int) * FSCK_MSG_MAX);
