	return count;
}

static void print_line_count(int count)
{
	switch (count) {
	case 0:
		printf("0,0");
		break;
	case 1:
		printf("1");
		break;
	default:
		printf("1,%d", count);
		break;
	}
}

static void copy_file_with_prefix(int prefix, const char *data, int size,
				  const char *set, const char *reset)
{
	int ch, nl_just_seen = 1;
	while (0 < size--) {
		ch = *data++;
		if (nl_just_seen) {
			fputs(set, stdout);
			putchar(prefix);
		}
		if (ch == '\n') {
			nl_just_seen = 1;
			fputs(reset, stdout);
		} else
			nl_just_seen = 0;
		putchar(ch);
	}
	if (!nl_just_seen)
		printf("%s\n\\ No newline at end of file\n", reset);
}

static void emit_rewrite_diff(const char *name_a,
