	       ent->s_lno + 1,
	       ent->lno + 1,
	       ent->num_lines);
	if (emit_one_suspect_detail(suspect) ||
	    (suspect->commit->object.flags & MORE_THAN_ONE_PATH))
		write_filename_info(suspect->path);

	cp = nth_line(sb, ent->lno);
