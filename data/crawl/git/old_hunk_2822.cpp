	if (type == DATE_STRFTIME)
		die("BUG: cannot create anonymous strftime date_mode struct");
	mode.type = type;
	return &mode;
}

