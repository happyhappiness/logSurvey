		} else {
			unlink(index_name);
			fd = open(index_name, O_CREAT|O_EXCL|O_WRONLY, 0600);
		}
		if (fd < 0)
			die_errno("unable to create '%s'", index_name);
		f = sha1fd(fd, index_name);
	}
