	if (line[len-1] == '\n')
		line[--len] = 0;
	if (!strcmp(line, "NAK"))
		return NAK;
	if (!prefixcmp(line, "ACK ")) {
		if (!get_sha1_hex(line+4, result_sha1)) {
			if (strstr(line+45, "continue"))
				return ACK_continue;
			if (strstr(line+45, "common"))
				return ACK_common;
			if (strstr(line+45, "ready"))
				return ACK_ready;
			return ACK;
		}
	}
	die("git fetch_pack: expected ACK/NAK, got '%s'", line);
