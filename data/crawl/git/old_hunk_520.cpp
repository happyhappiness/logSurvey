		}
		if (skip_prefix(line, "deepen-not ", &arg)) {
			char *ref = NULL;
			unsigned char sha1[20];
			if (expand_ref(arg, strlen(arg), sha1, &ref) != 1)
				die("git upload-pack: ambiguous deepen-not: %s", line);
			string_list_append(&deepen_not, ref);
			free(ref);
			deepen_rev_list = 1;
			continue;
		}
		if (!skip_prefix(line, "want ", &arg) ||
		    get_sha1_hex(arg, sha1_buf))
			die("git upload-pack: protocol error, "
			    "expected to get sha, not '%s'", line);

