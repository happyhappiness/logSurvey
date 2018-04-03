		putchar(inter_name_termination);
	}

	write_name_quoted(p->path, stdout, line_termination);
}

void show_combined_diff(struct combine_diff_path *p,
