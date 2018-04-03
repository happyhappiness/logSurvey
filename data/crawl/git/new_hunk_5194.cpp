		return;

	fputs(tag, stdout);
	write_name(ent->name, ent->len);
}

static void show_other_files(struct dir_struct *dir)
