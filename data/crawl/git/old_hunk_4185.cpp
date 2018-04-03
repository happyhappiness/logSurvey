			return 0;
		}
		printf("%-15s ", refname);

		buf = read_sha1_file(sha1, &type, &size);
		if (!buf || !size)
			return 0;

		/* skip header */
		sp = strstr(buf, "\n\n");
		if (!sp) {
			free(buf);
			return 0;
		}
		/* only take up to "lines" lines, and strip the signature */
		size = parse_signature(buf, size);
		for (i = 0, sp += 2;
				i < filter->lines && sp < buf + size;
				i++) {
			if (i)
				printf("\n    ");
			eol = memchr(sp, '\n', size - (sp - buf));
			len = eol ? eol - sp : size - (sp - buf);
			fwrite(sp, len, 1, stdout);
			if (!eol)
				break;
			sp = eol + 1;
		}
		putchar('\n');
		free(buf);
	}

	return 0;