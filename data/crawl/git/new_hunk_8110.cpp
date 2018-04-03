		size_t sz = 8192, term_len = command_buf.len - 5 - 2;
		length = 0;
		buffer = xmalloc(sz);
		for (;;) {
			read_line(&command_buf, stdin, '\n');
			if (command_buf.eof)
				die("EOF in data (terminator '%s' not found)", term);
			if (term_len == command_buf.len
				&& !strcmp(term, command_buf.buf))
				break;
			ALLOC_GROW(buffer, length + command_buf.len + 1, sz);
			memcpy(buffer + length,
				command_buf.buf,
				command_buf.len);
			length += command_buf.len;
			buffer[length++] = '\n';
		}
		free(term);
