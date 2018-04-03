 		}
 		if (!prefixcmp(line, "deepen ")) {
 			char *end;
-			use_thin_pack = 0;
 			depth = strtol(line + 7, &end, 0);
 			if (end == line + 7 || depth <= 0)
 				die("Invalid deepen: %s", line);
