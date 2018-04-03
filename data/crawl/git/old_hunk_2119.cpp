			core_eol = EOL_NATIVE;
		else
			core_eol = EOL_UNSET;
		if (core_eol == EOL_CRLF && auto_crlf == AUTO_CRLF_INPUT)
			return error("core.autocrlf=input conflicts with core.eol=crlf");
		return 0;
	}
