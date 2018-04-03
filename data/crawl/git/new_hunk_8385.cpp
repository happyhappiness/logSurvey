			die("Mark :%" PRIuMAX " not a commit", idnum);
		hashcpy(b->sha1, oe->sha1);
		buf = gfi_unpack_entry(oe, &size);
		cmd_from_commit(b, buf, size);
		free(buf);
	} else if (!get_sha1(from, b->sha1))
		cmd_from_existing(b);
	else
		die("Invalid ref name or SHA1 expression: %s", from);

	read_next_command();