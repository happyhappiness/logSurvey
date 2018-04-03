	else if (fmt & (DIFF_FORMAT_RAW | DIFF_FORMAT_NAME_STATUS))
		diff_flush_raw(p, opt);
	else if (fmt & DIFF_FORMAT_NAME)
		write_name_quoted(p->two->path, stdout, opt->line_termination);
}

static void show_file_mode_name(const char *newdelete, struct diff_filespec *fs)
{
	if (fs->mode)
		printf(" %s mode %06o ", newdelete, fs->mode);
	else
		printf(" %s ", newdelete);
	write_name_quoted(fs->path, stdout, '\n');
}


static void show_mode_change(struct diff_filepair *p, int show_name)
{
	if (p->one->mode && p->two->mode && p->one->mode != p->two->mode) {
		printf(" mode change %06o => %06o%c", p->one->mode, p->two->mode,
			show_name ? ' ' : '\n');
		if (show_name) {
			write_name_quoted(p->two->path, stdout, '\n');
		}
	}
}

