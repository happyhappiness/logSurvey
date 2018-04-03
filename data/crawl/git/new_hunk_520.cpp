		}
		if (skip_prefix(line, "deepen-not ", &arg)) {
			char *ref = NULL;
			struct object_id oid;
			if (expand_ref(arg, strlen(arg), oid.hash, &ref) != 1)
				die("git upload-pack: ambiguous deepen-not: %s", line);
			string_list_append(&deepen_not, ref);
			free(ref);
			deepen_rev_list = 1;
			continue;
		}
		if (!skip_prefix(line, "want ", &arg) ||
		    get_oid_hex(arg, &oid_buf))
			die("git upload-pack: protocol error, "
			    "expected to get sha, not '%s'", line);

