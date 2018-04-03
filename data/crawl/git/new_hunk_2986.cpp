		die("BUG: state file 'last' does not exist");
	state->last = strtol(sb.buf, NULL, 10);

	if (read_author_script(state) < 0)
		die(_("could not parse author script"));

	read_commit_msg(state);

	strbuf_release(&sb);
}

