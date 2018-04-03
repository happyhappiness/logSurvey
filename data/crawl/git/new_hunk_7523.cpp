static int inside_git_dir = -1;
static int inside_work_tree = -1;

static int sanitary_path_copy(char *dst, const char *src)
{
	char *dst0 = dst;

	if (*src == '/') {
		*dst++ = '/';
		while (*src == '/')
			src++;
	}

	for (;;) {
		char c = *src;

		/*
		 * A path component that begins with . could be
		 * special:
		 * (1) "." and ends   -- ignore and terminate.
		 * (2) "./"           -- ignore them, eat slash and continue.
		 * (3) ".." and ends  -- strip one and terminate.
		 * (4) "../"          -- strip one, eat slash and continue.
		 */
		if (c == '.') {
			switch (src[1]) {
			case '\0':
				/* (1) */
				src++;
				break;
			case '/':
				/* (2) */
				src += 2;
				while (*src == '/')
					src++;
				continue;
			case '.':
				switch (src[2]) {
				case '\0':
					/* (3) */
					src += 2;
					goto up_one;
				case '/':
					/* (4) */
					src += 3;
					while (*src == '/')
						src++;
					goto up_one;
				}
			}
		}

		/* copy up to the next '/', and eat all '/' */
		while ((c = *src++) != '\0' && c != '/')
			*dst++ = c;
		if (c == '/') {
			*dst++ = c;
			while (c == '/')
				c = *src++;
			src--;
		} else if (!c)
			break;
		continue;

	up_one:
		/*
		 * dst0..dst is prefix portion, and dst[-1] is '/';
		 * go up one level.
		 */
		dst -= 2; /* go past trailing '/' if any */
		if (dst < dst0)
			return -1;
		while (1) {
			if (dst <= dst0)
				break;
			c = *dst--;
			if (c == '/') {
				dst += 2;
				break;
			}
		}
	}
	*dst = '\0';
	return 0;
}

const char *prefix_path(const char *prefix, int len, const char *path)
{
	const char *orig = path;
	char *sanitized = xmalloc(len + strlen(path) + 1);
	if (*orig == '/')
		strcpy(sanitized, path);
	else {
		if (len)
			memcpy(sanitized, prefix, len);
		strcpy(sanitized + len, path);
	}
	if (sanitary_path_copy(sanitized, sanitized))
		goto error_out;
	if (*orig == '/') {
		const char *work_tree = get_git_work_tree();
		size_t len = strlen(work_tree);
		size_t total = strlen(sanitized) + 1;
		if (strncmp(sanitized, work_tree, len) ||
		    (sanitized[len] != '\0' && sanitized[len] != '/')) {
		error_out:
			error("'%s' is outside repository", orig);
			free(sanitized);
			return NULL;
		}
		if (sanitized[len] == '/')
			len++;
		memmove(sanitized, sanitized + len, total - len);
	}
	return sanitized;
}

/*
