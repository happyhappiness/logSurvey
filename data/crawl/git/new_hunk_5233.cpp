}


static void show_mode_change(FILE *file, struct diff_filepair *p, int show_name,
		const char *line_prefix)
{
	if (p->one->mode && p->two->mode && p->one->mode != p->two->mode) {
		fprintf(file, "%s mode change %06o => %06o%c", line_prefix, p->one->mode,
			p->two->mode, show_name ? ' ' : '\n');
		if (show_name) {
			write_name_quoted(p->two->path, file, '\n');
		}
	}
}

static void show_rename_copy(FILE *file, const char *renamecopy, struct diff_filepair *p,
			const char *line_prefix)
{
	char *names = pprint_rename(p->one->path, p->two->path);

	fprintf(file, " %s %s (%d%%)\n", renamecopy, names, similarity_index(p));
	free(names);
	show_mode_change(file, p, 0, line_prefix);
}

static void diff_summary(struct diff_options *opt, struct diff_filepair *p)
{
	FILE *file = opt->file;
	char *line_prefix = "";

	if (opt->output_prefix) {
		struct strbuf *buf = opt->output_prefix(opt, opt->output_prefix_data);
		line_prefix = buf->buf;
	}

	switch(p->status) {
	case DIFF_STATUS_DELETED:
		fputs(line_prefix, file);
		show_file_mode_name(file, "delete", p->one);
		break;
	case DIFF_STATUS_ADDED:
		fputs(line_prefix, file);
		show_file_mode_name(file, "create", p->two);
		break;
	case DIFF_STATUS_COPIED:
		fputs(line_prefix, file);
		show_rename_copy(file, "copy", p, line_prefix);
		break;
	case DIFF_STATUS_RENAMED:
		fputs(line_prefix, file);
		show_rename_copy(file, "rename", p, line_prefix);
		break;
	default:
		if (p->score) {
			fprintf(file, "%s rewrite ", line_prefix);
			write_name_quoted(p->two->path, file, ' ');
			fprintf(file, "(%d%%)\n", similarity_index(p));
		}
		show_mode_change(file, p, !p->score, line_prefix);
		break;
	}
}
