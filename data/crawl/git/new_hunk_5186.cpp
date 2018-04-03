
	if (!strcmp(var, "core.autocrlf")) {
		if (value && !strcasecmp(value, "input")) {
			if (eol == EOL_CRLF)
				return error("core.autocrlf=input conflicts with core.eol=crlf");
			auto_crlf = AUTO_CRLF_INPUT;
			return 0;
		}
