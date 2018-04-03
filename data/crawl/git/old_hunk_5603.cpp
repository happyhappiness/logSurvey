	if (line[len-1] == '\n')
		line[--len] = 0;
	if (!strcmp(line, "NAK"))
		return 0;
	if (!prefixcmp(line, "ACK ")) {
		if (!get_sha1_hex(line+4, result_sha1)) {
			if (strstr(line+45, "continue"))
				return 2;
			return 1;
		}
	}
	die("git fetch_pack: expected ACK/NAK, got '%s'", line);
