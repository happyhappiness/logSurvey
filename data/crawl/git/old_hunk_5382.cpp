			message = "(revision walker failed)";
	}

	strbuf_addf(&sb, "Submodule %s %s..", path,
			find_unique_abbrev(one, DEFAULT_ABBREV));
	if (!fast_backward && !fast_forward)
		strbuf_addch(&sb, '.');
	strbuf_addf(&sb, "%s", find_unique_abbrev(two, DEFAULT_ABBREV));
	if (dirty_submodule)
		strbuf_add(&sb, "-dirty", 6);
	if (message)
		strbuf_addf(&sb, " %s\n", message);
	else
