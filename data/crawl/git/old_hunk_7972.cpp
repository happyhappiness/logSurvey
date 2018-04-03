	fputs(pre, output);
	if (patch->old_name && patch->new_name &&
	    strcmp(patch->old_name, patch->new_name)) {
		write_name_quoted(NULL, 0, patch->old_name, 1, output);
		fputs(" => ", output);
		write_name_quoted(NULL, 0, patch->new_name, 1, output);
	}
	else {
		const char *n = patch->new_name;
		if (!n)
			n = patch->old_name;
		write_name_quoted(NULL, 0, n, 1, output);
	}
	fputs(post, output);
}
