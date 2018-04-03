	el->filebuf = NULL;
}

static void check_trailing_spaces(const char *fname, char *buf)
{
	int i, last_space = -1, len = strlen(buf);
	for (i = 0; i < len; i++)
		if (buf[i] == '\\')
			i++;
		else if (buf[i] == ' ')
			last_space = i;
		else
			last_space = -1;

	if (last_space == len - 1)
		warning(_("%s: trailing spaces in '%s'. Please quote or remove them."),
			fname, buf);
}

int add_excludes_from_file_to_list(const char *fname,
				   const char *base,
				   int baselen,
