		if (buffer[len-1] == '\n')
			buffer[--len] = 0;

		if (len > 4 && !prefixcmp(buffer, "ERR "))
			die("remote error: %s", buffer + 4);

		if (len < 42 || get_sha1_hex(buffer, old_sha1) || buffer[40] != ' ')
			die("protocol error: expected sha/ref, got '%s'", buffer);
		name = buffer + 41;