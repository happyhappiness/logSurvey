	}

	/* sanity checks, pathspec matchers assume these are sane */
	assert(item->nowildcard_len <= item->len &&
	       item->prefix         <= item->len);
}

static int pathspec_item_cmp(const void *a_, const void *b_)
