		strbuf_release(&m);
		if (!stat(git_path("MERGE_MODE"), &statbuf)) {
			if (strbuf_read_file(&sb, git_path("MERGE_MODE"), 0) < 0)
				die_errno("could not read MERGE_MODE");
			if (!strcmp(sb.buf, "no-ff"))
				allow_fast_forward = 0;
		}
