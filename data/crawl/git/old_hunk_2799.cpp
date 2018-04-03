			die(_("--column and -n are incompatible"));
		colopts = 0;
	}
	if (cmdmode == 'l') {
		int ret;
		if (column_active(colopts)) {
