		}
		if (prefixcmp(line, "want ") ||
		    get_sha1_hex(line+5, sha1_buf))
			die("git upload-pack: protocol error, "
			    "expected to get sha, not '%s'", line);
		if (strstr(line+45, "multi_ack"))
			multi_ack = 1;
