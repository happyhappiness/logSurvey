		return;

	fputs(tag, stdout);
	write_name_quoted("", 0, ent->name + offset, line_terminator, stdout);
	putchar(line_terminator);
}

static void show_other_files(struct dir_struct *dir)
