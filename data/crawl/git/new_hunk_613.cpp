
	flushes = 0;
	retval = -1;
	while ((oid = get_rev())) {
		packet_buf_write(&req_buf, "have %s\n", oid_to_hex(oid));
		print_verbose(args, "have %s", oid_to_hex(oid));
		in_vain++;
		if (flush_at <= ++count) {
			int ack;
