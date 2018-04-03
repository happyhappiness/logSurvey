		fmt++;
	} while (*buf && *fmt);
	printf("left: %s\n", buf);
	return mktime(&tm);
}

static int convert_date_line(char *dst, void **buf, unsigned long *sp)
