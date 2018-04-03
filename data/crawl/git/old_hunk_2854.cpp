			usage_with_options(git_notes_merge_usage, options);
		}
	} else {
		git_config_get_notes_strategy("notes.mergeStrategy", &o.strategy);
	}

	strbuf_addf(&msg, "notes: Merged notes from %s into %s",
