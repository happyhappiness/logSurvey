	const char *branch_status_color = color(WT_STATUS_HEADER, s);

	if (s->branch) {
		const char *on_what = "On branch ";
		const char *branch_name = s->branch;
		if (!prefixcmp(branch_name, "refs/heads/"))
			branch_name += 11;
		else if (!strcmp(branch_name, "HEAD")) {
			branch_name = "";
			branch_status_color = color(WT_STATUS_NOBRANCH, s);
			on_what = "Not currently on any branch.";
		}
		status_printf(s, color(WT_STATUS_HEADER, s), "");
		status_printf_more(s, branch_status_color, "%s", on_what);
