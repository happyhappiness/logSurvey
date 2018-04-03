	}

	if (prefix_offset > max || memcmp(prev, prefix, prefix_offset))
		die("git ls-files: cannot generate relative filenames containing '..'");

	prefix_len = max;
	return max ? xmemdupz(prev, max) : NULL;
