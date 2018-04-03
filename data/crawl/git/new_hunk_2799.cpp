			die(_("--column and -n are incompatible"));
		colopts = 0;
	}
	if (!sorting)
		sorting = ref_default_sorting();
	if (cmdmode == 'l') {
		int ret;
		if (column_active(colopts)) {
