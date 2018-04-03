
	len = vsnprintf(tmp, sizeof(tmp), fmt, ap);
	if (len < 0)
		die("Fatal: Out of memory\n");
	if (len >= sizeof(tmp))
		die("imap command overflow !\n");
	*strp = xmemdupz(tmp, len);
	return len;
}
