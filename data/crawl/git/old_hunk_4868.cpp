	struct stat st;
	unsigned char sha1[20];
	if (fstat(fd, &st) < 0 ||
	    index_fd(sha1, fd, &st, write_object, type_from_string(type), path))
		die(write_object
		    ? "Unable to add %s to database"
		    : "Unable to hash %s", path);