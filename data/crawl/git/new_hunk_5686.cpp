		if (!prefixcmp(line, "shallow ")) {
			unsigned char sha1[20];
			struct object *object;
			if (get_sha1(line + 8, sha1))
				die("invalid shallow line: %s", line);
			object = parse_object(sha1);
