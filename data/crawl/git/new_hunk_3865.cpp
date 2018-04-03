		len = packet_read_line(in, line, sizeof(line));
		if (!len)
			break;
		if (prefixcmp(line, "ok ") && prefixcmp(line, "ng ")) {
			error("invalid ref status from remote: %s", line);
			ret = -1;
			break;
		}