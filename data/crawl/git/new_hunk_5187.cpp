		return 0;
	}

	if (!strcmp(var, "core.eol")) {
		if (value && !strcasecmp(value, "lf"))
			eol = EOL_LF;
		else if (value && !strcasecmp(value, "crlf"))
			eol = EOL_CRLF;
		else if (value && !strcasecmp(value, "native"))
			eol = EOL_NATIVE;
		else
			eol = EOL_UNSET;
		if (eol == EOL_CRLF && auto_crlf == AUTO_CRLF_INPUT)
			return error("core.autocrlf=input conflicts with core.eol=crlf");
		return 0;
	}

	if (!strcmp(var, "core.notesref")) {
		notes_ref_name = xstrdup(value);
		return 0;
