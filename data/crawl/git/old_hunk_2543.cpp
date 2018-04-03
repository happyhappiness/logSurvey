	if (!parse_commit(commit))
		pp_commit_easy(CMIT_FMT_ONELINE, commit, &sb);
	fprintf(stderr, "%s %s... %s\n", msg,
		find_unique_abbrev(commit->object.sha1, DEFAULT_ABBREV), sb.buf);
	strbuf_release(&sb);
}
