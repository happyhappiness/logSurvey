	tz = strtoul(tz_c, NULL, 10);
	if (get_sha1_hex(logdata, sha1))
		die("Log %s is corrupt.", logfile);
	if (msg)
		*msg = ref_msg(logdata, logend);
	munmap(log_mapped, mapsz);
