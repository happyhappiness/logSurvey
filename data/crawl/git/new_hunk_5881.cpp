
		fp = fopen(git_path("FETCH_HEAD"), "r");
		if (!fp)
			die_errno("could not open '%s' for reading",
				  git_path("FETCH_HEAD"));
		strbuf_getline(&line, fp, '\n');
		fclose(fp);
		ptr = strstr(line.buf, "\tnot-for-merge\t");
