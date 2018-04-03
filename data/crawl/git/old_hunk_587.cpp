		hashmap_entry_init(entry, strhash(buf.buf));
		hashmap_add(result, entry);
	}
	if (finish_command(&diff_files))
		die("diff-files did not exit properly");
	strbuf_release(&index_env);
