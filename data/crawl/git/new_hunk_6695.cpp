		printf("%s %d %d %d\n",
		       sha1_to_hex(suspect->commit->object.sha1),
		       ent->s_lno + 1, ent->lno + 1, ent->num_lines);
		emit_one_suspect_detail(suspect);
		write_filename_info(suspect->path);
		maybe_flush_or_die(stdout, "stdout");
	}