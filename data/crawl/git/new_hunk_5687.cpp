		}
		if (!prefixcmp(line, "deepen ")) {
			char *end;
			depth = strtol(line + 7, &end, 0);
			if (end == line + 7 || depth <= 0)
				die("Invalid deepen: %s", line);
