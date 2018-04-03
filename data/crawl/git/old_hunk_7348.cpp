		printf("%s", n->tag->tag);
	else
		printf("%s", n->path);
	if (longformat)
		printf("-0-g%s",
		       find_unique_abbrev(n->tag->tagged->sha1, abbrev));
}

static void describe(const char *arg, int last_one)
