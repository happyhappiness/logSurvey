		fprintf(file, "%s\n\\ No newline at end of file\n", reset);
}

static void emit_rewrite_diff(const char *name_a,
			      const char *name_b,
			      struct diff_filespec *one,
