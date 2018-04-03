		name_a = p->two->path;
		name_b = NULL;
		strip_prefix(opt->prefix_length, &name_a, &name_b);
		write_name_quoted(name_a, stdout, opt->line_termination);
	}
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

static void show_rename_copy(const char *renamecopy, struct diff_filepair *p)
{
	char *names = pprint_rename(p->one->path, p->two->path);

	printf(" %s %s (%d%%)\n", renamecopy, names, similarity_index(p));
	free(names);
	show_mode_change(p, 0);
}

static void diff_summary(struct diff_filepair *p)
{
	switch(p->status) {
	case DIFF_STATUS_DELETED:
		show_file_mode_name("delete", p->one);
		break;
	case DIFF_STATUS_ADDED:
		show_file_mode_name("create", p->two);
		break;
	case DIFF_STATUS_COPIED:
		show_rename_copy("copy", p);
		break;
	case DIFF_STATUS_RENAMED:
		show_rename_copy("rename", p);
		break;
	default:
		if (p->score) {
			fputs(" rewrite ", stdout);
			write_name_quoted(p->two->path, stdout, ' ');
			printf("(%d%%)\n", similarity_index(p));
		}
		show_mode_change(p, !p->score);
		break;
	}
}
