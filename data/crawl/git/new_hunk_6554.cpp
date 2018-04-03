
	len = vsnprintf(tmp, sizeof(tmp), fmt, ap);
	if (len < 0)
		die("Fatal: Out of memory");
	if (len >= sizeof(tmp))
		die("imap command overflow!");
	*strp = xmemdupz(tmp, len);
	return len;
}
