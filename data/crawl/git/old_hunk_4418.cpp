	}

	if (!msg->buf.len) {
		fprintf(stderr, "Removing note for object %s\n",
			sha1_to_hex(object));
		hashclr(result);
	} else {
		if (write_sha1_file(msg->buf.buf, msg->buf.len, blob_type, result)) {
			error("unable to write note object");
			if (path)
				error("The note contents has been left in %s",
				      path);
			exit(128);
		}
