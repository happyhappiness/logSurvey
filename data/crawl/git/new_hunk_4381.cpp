	fwrite(sb.buf, sb.len, 1, f);

	if (!message) {
		print_submodule_summary(&rev, f, del, add, reset);
		clear_commit_marks(left, ~0);
		clear_commit_marks(right, ~0);
	}

	strbuf_release(&sb);
}
