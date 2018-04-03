		fd = open(index_name, O_CREAT|O_EXCL|O_WRONLY, 0600);
	}
	if (fd < 0)
		die_errno("unable to create '%s'", index_name);
	f = sha1fd(fd, index_name);

	/* if last object's offset is >= 2^31 we should use index V2 */
