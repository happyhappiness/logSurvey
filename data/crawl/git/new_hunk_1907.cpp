		packet_buf_write(&req_buf, "done\n");
		send_request(args, fd[1], &req_buf);
	}
	print_verbose(args, _("done"));
	if (retval != 0) {
		multi_ack = 0;
		flushes++;
