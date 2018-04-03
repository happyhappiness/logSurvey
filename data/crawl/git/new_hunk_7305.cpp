			line[0] = bytes - 26 + 'a' - 1;
		encode_85(line + 1, cp, bytes);
		cp = (char *) cp + bytes;
		fputs(line, file);
		fputc('\n', file);
	}
	fprintf(file, "\n");
	free(data);
}

static void emit_binary_diff(FILE *file, mmfile_t *one, mmfile_t *two)
{
	fprintf(file, "GIT binary patch\n");
	emit_binary_diff_body(file, one, two);
	emit_binary_diff_body(file, two, one);
}

static void setup_diff_attr_check(struct git_attr_check *check)
