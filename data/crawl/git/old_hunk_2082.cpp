		if ((dir = opendir(name)) == NULL) {
			if (errno == ENOENT)
				continue;
			error("cannot opendir %s (%s)", name, strerror(errno));
			goto out;
		}

