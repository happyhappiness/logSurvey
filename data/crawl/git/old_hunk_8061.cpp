		else
			sha1_ptr = sha1;

		printf("%06o %s	",patch->old_mode, sha1_to_hex(sha1_ptr));
		if (line_termination && quote_c_style(name, NULL, NULL, 0))
			quote_c_style(name, NULL, stdout, 0);
		else
			fputs(name, stdout);
		putchar(line_termination);
	}
}

static void stat_patch_list(struct patch *patch)
