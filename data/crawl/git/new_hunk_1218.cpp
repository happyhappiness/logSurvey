		*opt_value = PATCH_FORMAT_STGIT_SERIES;
	else if (!strcmp(arg, "hg"))
		*opt_value = PATCH_FORMAT_HG;
	else if (!strcmp(arg, "mboxrd"))
		*opt_value = PATCH_FORMAT_MBOXRD;
	else
		return error(_("Invalid value for --patch-format: %s"), arg);
	return 0;
