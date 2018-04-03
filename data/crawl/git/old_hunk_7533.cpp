			    len - trailing_whitespace, 1, stream);
			fputs(reset, stream);
		}
		if (trailing_newline)
			fputc('\n', stream);
	}