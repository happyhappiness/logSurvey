			if (retval)
				return -1;
			continue;
		} else if (S_ISGITLINK(entry.mode)) {
			int retval;
			struct strbuf path;
			unsigned int entrylen;
			struct commit *commit;

			entrylen = tree_entry_len(entry.path, entry.sha1);
			strbuf_init(&path, baselen + entrylen + 1);
			strbuf_add(&path, base, baselen);
			strbuf_add(&path, entry.path, entrylen);
			strbuf_addch(&path, '/');

			commit = lookup_commit(entry.sha1);
			if (!commit)
				die("Commit %s in submodule path %s not found",
				    sha1_to_hex(entry.sha1), path.buf);

			if (parse_commit(commit))
				die("Invalid commit %s in submodule path %s",
				    sha1_to_hex(entry.sha1), path.buf);

			retval = read_tree_recursive(commit->tree,
						     path.buf, path.len,
						     stage, match, fn, context);
			strbuf_release(&path);
			if (retval)
				return -1;
			continue;
		}
	}
	return 0;