	sline->p_lno[i] = sline->p_lno[j];
}

static void dump_quoted_path(const char *prefix, const char *path,
			     const char *c_meta, const char *c_reset)
{
	printf("%s%s", c_meta, prefix);
	quote_c_style(path, NULL, stdout, 0);
	printf("%s\n", c_reset);
}

static void show_patch_diff(struct combine_diff_path *elem, int num_parent,
