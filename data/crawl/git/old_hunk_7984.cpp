	else if (fmt & (DIFF_FORMAT_RAW | DIFF_FORMAT_NAME_STATUS))
		diff_flush_raw(p, opt);
	else if (fmt & DIFF_FORMAT_NAME)
		diff_flush_name(p, opt);
}

static void show_file_mode_name(const char *newdelete, struct diff_filespec *fs)
{
	char *name = quote_one(fs->path);
	if (fs->mode)
		printf(" %s mode %06o %s\n", newdelete, fs->mode, name);
	else
		printf(" %s %s\n", newdelete, name);
	free(name);
}


static void show_mode_change(struct diff_filepair *p, int show_name)
{
	if (p->one->mode && p->two->mode && p->one->mode != p->two->mode) {
		if (show_name) {
			char *name = quote_one(p->two->path);
			printf(" mode change %06o => %06o %s\n",
			       p->one->mode, p->two->mode, name);
			free(name);
		}
		else
			printf(" mode change %06o => %06o\n",
			       p->one->mode, p->two->mode);
	}
}

