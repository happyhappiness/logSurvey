
	if (!show_stage) {
		fputs(tag, stdout);
		write_name_quoted("", 0, ce->name + offset,
				  line_terminator, stdout);
		putchar(line_terminator);
	}
	else {
		printf("%s%06o %s %d\t",
		       tag,
		       ntohl(ce->ce_mode),
		       abbrev ? find_unique_abbrev(ce->sha1,abbrev)
				: sha1_to_hex(ce->sha1),
		       ce_stage(ce));
		write_name_quoted("", 0, ce->name + offset,
				  line_terminator, stdout);
		putchar(line_terminator);
	}
}

static void show_files(struct dir_struct *dir, const char *prefix)
