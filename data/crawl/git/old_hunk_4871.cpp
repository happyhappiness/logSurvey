		if (fd < 0)
			return error("open(\"%s\"): %s", path,
				     strerror(errno));
		if (index_fd(sha1, fd, st, write_object, OBJ_BLOB, path) < 0)
			return error("%s: failed to insert into database",
				     path);
		break;
