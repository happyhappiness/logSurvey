		strbuf_addf(&sb, "%s:%s\n", fast_backward ? " (rewind)" : "", reset);
	fwrite(sb.buf, sb.len, 1, f);

	if (!message) /* only NULL if we succeeded in setting up the walk */
		print_submodule_summary(&rev, f, line_prefix, del, add, reset);
	if (left)
		clear_commit_marks(left, ~0);
	if (right)
		clear_commit_marks(right, ~0);

	strbuf_release(&sb);
}

void set_config_fetch_recurse_submodules(int value)
{
	config_fetch_recurse_submodules = value;