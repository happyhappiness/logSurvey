			die("Invalid SHA-1: %s", buffer);
		sha1_array_append(&skiplist, oid.hash);
		if (sorted && skiplist.nr > 1 &&
				oidcmp(&skiplist.oid[skiplist.nr - 2],
				       &oid) > 0)
			sorted = 0;
	}
	close(fd);
