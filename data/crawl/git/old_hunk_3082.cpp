		mode->type = DATE_NORMAL;
	else if (!strcmp(format, "raw"))
		mode->type = DATE_RAW;
	else
		die("unknown date format %s", format);
}

