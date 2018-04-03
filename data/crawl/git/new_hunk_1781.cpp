	pp_title_line(&pp, &msg, &sb, encoding, need_8bit_cte);
	pp_remainder(&pp, &msg, &sb, 0);
	add_branch_description(&sb, branch_name);
	fprintf(rev->diffopt.file, "%s\n", sb.buf);

	strbuf_release(&sb);

