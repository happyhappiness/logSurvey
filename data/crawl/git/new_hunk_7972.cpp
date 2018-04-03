	fputs(pre, output);
	if (patch->old_name && patch->new_name &&
	    strcmp(patch->old_name, patch->new_name)) {
		quote_c_style(patch->old_name, NULL, output, 0);
		fputs(" => ", output);
		quote_c_style(patch->new_name, NULL, output, 0);
	} else {
		const char *n = patch->new_name;
		if (!n)
			n = patch->old_name;
		quote_c_style(n, NULL, output, 0);
	}
	fputs(post, output);
}
