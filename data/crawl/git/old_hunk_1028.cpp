	writer.git_cmd = 1;
	if (start_command(&writer)) {
		int err = errno;
		packet_write(1, "NACK unable to spawn subprocess\n");
		die("upload-archive: %s", strerror(err));
	}

	packet_write(1, "ACK\n");
	packet_flush(1);

	while (1) {
