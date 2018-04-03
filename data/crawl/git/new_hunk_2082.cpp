		if ((dir = opendir(name)) == NULL) {
			if (errno == ENOENT)
				continue;
			error_errno("cannot opendir %s", name);
			goto out;
		}

