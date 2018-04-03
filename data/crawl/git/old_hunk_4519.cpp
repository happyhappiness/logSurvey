
		if (launch_editor(path, buf, NULL)) {
			fprintf(stderr,
			"Please supply the message using either -m or -F option.\n");
			exit(1);
		}
	}

	stripspace(buf, 1);

	if (!message && !buf->len)
		die("no tag message?");

	strbuf_insert(buf, 0, header_buf, header_len);

	if (build_tag_object(buf, sign, result) < 0) {
		if (path)
			fprintf(stderr, "The tag message has been left in %s\n",
				path);
		exit(128);
	}
