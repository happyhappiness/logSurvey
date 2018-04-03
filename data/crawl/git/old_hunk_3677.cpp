	if (len > sizeof(line))
		die("too long a refname '%s'", entry->name);
	write_or_die(*fd, line, len);
	return 0;
}

