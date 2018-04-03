		}
		fclose(fp);
		strbuf_release(&m);
		if (!stat(git_path_merge_mode(), &statbuf)) {
			if (strbuf_read_file(&sb, git_path_merge_mode(), 0) < 0)
				die_errno(_("could not read MERGE_MODE"));
			if (!strcmp(sb.buf, "no-ff"))
				allow_fast_forward = 0;
