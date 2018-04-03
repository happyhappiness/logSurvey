	if (data->type == OBJ_BLOB) {
		if (opt->buffer_output)
			fflush(stdout);
		if (opt->cmdmode) {
			char *contents;
			unsigned long size;

			if (!data->rest)
				die("missing path for '%s'", sha1_to_hex(sha1));

			if (opt->cmdmode == 'w') {
				if (filter_object(data->rest, 0100644, sha1,
						  &contents, &size))
					die("could not convert '%s' %s",
					    sha1_to_hex(sha1), data->rest);
			} else if (opt->cmdmode == 'c') {
				enum object_type type;
				if (!textconv_object(data->rest, 0100644, sha1,
						     1, &contents, &size))
					contents = read_sha1_file(sha1, &type,
								  &size);
				if (!contents)
					die("could not convert '%s' %s",
					    sha1_to_hex(sha1), data->rest);
			} else
				die("BUG: invalid cmdmode: %c", opt->cmdmode);
			batch_write(opt, contents, size);
			free(contents);
		} else if (stream_blob_to_fd(1, sha1, NULL, 0) < 0)
			die("unable to stream %s to stdout", sha1_to_hex(sha1));
	}
	else {
