		printf("%s ",
		       diff_unique_abbrev(p->two->sha1, abbrev));
	}
	printf("%s%c%s", status, inter_name_termination, path_one);
	if (two_paths)
		printf("%c%s", inter_name_termination, path_two);
	putchar(line_termination);
