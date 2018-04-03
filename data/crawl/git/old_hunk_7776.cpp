
	if (!new_refs)
		fprintf(stderr, "Everything up-to-date\n");
	for (ref = remote_refs; ref; ref = ref->next) {
		switch (ref->status) {
		case REF_STATUS_NONE:
