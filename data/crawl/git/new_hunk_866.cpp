	item->len = strlen(item->match);
	item->prefix = prefixlen;

	if (flags & PATHSPEC_STRIP_SUBMODULE_SLASH_CHEAP)
		strip_submodule_slash_cheap(item);

	if (flags & PATHSPEC_STRIP_SUBMODULE_SLASH_EXPENSIVE)
		strip_submodule_slash_expensive(item);

	if (magic & PATHSPEC_LITERAL)
		item->nowildcard_len = item->len;