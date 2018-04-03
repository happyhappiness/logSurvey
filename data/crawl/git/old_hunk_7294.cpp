		len--;
	}

	fputs(diff_get_color(1, color), stdout);
	fwrite(ptr, len, 1, stdout);
	fputs(diff_get_color(1, DIFF_RESET), stdout);

	if (eol) {
		if (suppress_newline)
			buffer->suppressed_newline = 1;
		else
			putchar('\n');
	}
}

