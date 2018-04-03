		}
		strbuf_addf(&buf, "%s\n", sha1_to_hex(sha1));
	}
	filename = git_path_merge_head();
	fd = open(filename, O_WRONLY | O_CREAT, 0666);
	if (fd < 0)
		die_errno(_("Could not open '%s' for writing"), filename);
