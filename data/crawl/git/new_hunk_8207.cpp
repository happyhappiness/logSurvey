	unsigned long size = 0;

	type = sha1_object_info(object, NULL);
	if (type <= OBJ_NONE)
	    die("bad object type.");

	header_len = snprintf(header_buf, sizeof(header_buf),
