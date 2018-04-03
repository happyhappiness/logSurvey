			usage_with_options(git_notes_merge_usage, options);
		}
	} else {
		struct strbuf merge_key = STRBUF_INIT;
		const char *short_ref = NULL;

		if (!skip_prefix(o.local_ref, "refs/notes/", &short_ref))
			die("BUG: local ref %s is outside of refs/notes/",
			    o.local_ref);

		strbuf_addf(&merge_key, "notes.%s.mergeStrategy", short_ref);

		if (git_config_get_notes_strategy(merge_key.buf, &o.strategy))
			git_config_get_notes_strategy("notes.mergeStrategy", &o.strategy);

		strbuf_release(&merge_key);
	}

	strbuf_addf(&msg, "notes: Merged notes from %s into %s",
