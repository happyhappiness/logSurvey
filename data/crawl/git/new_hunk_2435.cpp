
	if (item->object.parsed)
		return 0;
	data = read_sha1_file(item->object.oid.hash, &type, &size);
	if (!data)
		return error("Could not read %s",
			     oid_to_hex(&item->object.oid));
