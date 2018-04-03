		putchar(inter_name_termination);
	}

	if (line_termination) {
		if (quote_c_style(p->path, NULL, NULL, 0))
			quote_c_style(p->path, NULL, stdout, 0);
		else
			printf("%s", p->path);
		putchar(line_termination);
	}
	else {
		printf("%s%c", p->path, line_termination);
	}
}

void show_combined_diff(struct combine_diff_path *p,
