
	if (item->object.parsed)
		return 0;
	data = read_sha1_file(item->object.sha1, &type, &size);
	if (!data)
		return error("Could not read %s",
			     sha1_to_hex(item->object.sha1));
