	status_printf(s, color(WT_STATUS_HEADER, s), "\t");
	what = wt_status_diff_status_string(status);
	if (!what)
		die("BUG: unhandled diff status %c", status);
	len = label_width - utf8_strwidth(what);
	assert(len >= 0);
	if (status == DIFF_STATUS_COPIED || status == DIFF_STATUS_RENAMED)