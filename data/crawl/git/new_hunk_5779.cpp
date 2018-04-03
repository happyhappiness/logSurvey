		discard_cache();
		if (read_cache() < 0)
			die("failed to read the cache");
		return ret;
	}
}

