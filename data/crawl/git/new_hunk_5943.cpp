
	if (fsck_object(obj, 1, fsck_error_function))
		die("Error in object");
	if (!fsck_walk(obj, check_object, NULL))
		die("Error on reachable objects of %s", sha1_to_hex(obj->sha1));
	write_cached_object(obj);
	return 1;
