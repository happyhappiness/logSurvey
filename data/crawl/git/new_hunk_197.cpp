		return CHECK_WARN;
	if (!strcasecmp("error", value))
		return CHECK_ERROR;
	warning(_("unrecognized setting %s for option "
		  "rebase.missingCommitsCheck. Ignoring."), value);
	return CHECK_IGNORE;
}