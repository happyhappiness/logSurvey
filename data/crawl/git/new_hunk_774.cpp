		name_a = p->two->path;
		name_b = NULL;
		strip_prefix(opt->prefix_length, &name_a, &name_b);
		fprintf(opt->file, "%s", diff_line_prefix(opt));
		write_name_quoted(name_a, opt->file, opt->line_termination);
	}
}
