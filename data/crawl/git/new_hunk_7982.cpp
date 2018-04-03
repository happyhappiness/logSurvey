			printf("-\t-\t");
		else
			printf("%d\t%d\t", file->added, file->deleted);
		if (!file->is_renamed) {
			write_name_quoted(file->name, stdout, options->line_termination);
		} else {
			fputs(file->name, stdout);
			putchar(options->line_termination);
		}
	}
}

