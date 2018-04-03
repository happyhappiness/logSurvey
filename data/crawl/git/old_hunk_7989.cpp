		if (get_sha1_hex(tab - 40, sha1) || tab[-41] != ' ')
			goto bad_line;

		if (line_termination && ptr[0] == '"')
			path_name = unquote_c_style(ptr, NULL);
		else
			path_name = ptr;

		if (!verify_path(path_name)) {
			fprintf(stderr, "Ignoring path %s\n", path_name);
			if (path_name != ptr)
				free(path_name);
			continue;
		}

