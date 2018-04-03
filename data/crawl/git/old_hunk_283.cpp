		fd = xmks_tempfile(&temp, git_path("shallow_XXXXXX"));

		if (write_in_full(fd, sb.buf, sb.len) != sb.len ||
		    close_tempfile(&temp) < 0)
			die_errno("failed to write to %s",
				  get_tempfile_path(&temp));
		strbuf_release(&sb);
