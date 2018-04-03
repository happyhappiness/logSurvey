		name_a = p->two->path;
		name_b = NULL;
		strip_prefix(opt->prefix_length, &name_a, &name_b);
		write_name_quoted(name_a, opt->file, opt->line_termination);
	}
}

static void show_file_mode_name(FILE *file, const char *newdelete, struct diff_filespec *fs)
{
	if (fs->mode)
		fprintf(file, " %s mode %06o ", newdelete, fs->mode);
	else
		fprintf(file, " %s ", newdelete);
	write_name_quoted(fs->path, file, '\n');
}


static void show_mode_change(FILE *file, struct diff_filepair *p, int show_name)
{
	if (p->one->mode && p->two->mode && p->one->mode != p->two->mode) {
		fprintf(file, " mode change %06o => %06o%c", p->one->mode, p->two->mode,
			show_name ? ' ' : '\n');
		if (show_name) {
			write_name_quoted(p->two->path, file, '\n');
		}
	}
}

static void show_rename_copy(FILE *file, const char *renamecopy, struct diff_filepair *p)
{
	char *names = pprint_rename(p->one->path, p->two->path);

	fprintf(file, " %s %s (%d%%)\n", renamecopy, names, similarity_index(p));
	free(names);
	show_mode_change(file, p, 0);
}

static void diff_summary(FILE *file, struct diff_filepair *p)
{
	switch(p->status) {
	case DIFF_STATUS_DELETED:
		show_file_mode_name(file, "delete", p->one);
		break;
	case DIFF_STATUS_ADDED:
		show_file_mode_name(file, "create", p->two);
		break;
	case DIFF_STATUS_COPIED:
		show_rename_copy(file, "copy", p);
		break;
	case DIFF_STATUS_RENAMED:
		show_rename_copy(file, "rename", p);
		break;
	default:
		if (p->score) {
			fputs(" rewrite ", file);
			write_name_quoted(p->two->path, file, ' ');
			fprintf(file, "(%d%%)\n", similarity_index(p));
		}
		show_mode_change(file, p, !p->score);
		break;
	}
}
