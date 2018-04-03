	refspec_nr = nr;
}

static int expand_one_ref(const char *ref, const unsigned char *sha1, int flag, void *cb_data)
{
	/* Ignore the "refs/" at the beginning of the refname */
	ref += 5;

	if (!prefixcmp(ref, "tags/"))
		add_refspec(xstrdup(ref));
	return 0;
}

static void expand_refspecs(void)
{
	if (all) {
		if (refspec_nr)
			die("cannot mix '--all' and a refspec");

		/*
		 * No need to expand "--all" - we'll just use
		 * the "--all" flag to send-pack
		 */
		return;
	}
	if (!tags)
		return;
	for_each_ref(expand_one_ref, NULL);
}

struct wildcard_cb {
	const char *from_prefix;
	int from_prefix_len;
	const char *to_prefix;
	int to_prefix_len;
	int force;
};

static int expand_wildcard_ref(const char *ref, const unsigned char *sha1, int flag, void *cb_data)
{
	struct wildcard_cb *cb = cb_data;
	int len = strlen(ref);
	char *expanded, *newref;

	if (len < cb->from_prefix_len ||
	    memcmp(cb->from_prefix, ref, cb->from_prefix_len))
		return 0;
	expanded = xmalloc(len * 2 + cb->force +
			   (cb->to_prefix_len - cb->from_prefix_len) + 2);
	newref = expanded + cb->force;
	if (cb->force)
		expanded[0] = '+';
	memcpy(newref, ref, len);
	newref[len] = ':';
	memcpy(newref + len + 1, cb->to_prefix, cb->to_prefix_len);
	strcpy(newref + len + 1 + cb->to_prefix_len,
	       ref + cb->from_prefix_len);
	add_refspec(expanded);
	return 0;
}

static int wildcard_ref(const char *ref)
{
	int len;
	const char *colon;
	struct wildcard_cb cb;

	memset(&cb, 0, sizeof(cb));
	if (ref[0] == '+') {
		cb.force = 1;
		ref++;
	}
	len = strlen(ref);
	colon = strchr(ref, ':');
	if (! (colon && ref < colon &&
	       colon[-2] == '/' && colon[-1] == '*' &&
	       /* "<mine>/<asterisk>:<yours>/<asterisk>" is at least 7 bytes */
	       7 <= len &&
	       ref[len-2] == '/' && ref[len-1] == '*') )
		return 0 ;
	cb.from_prefix = ref;
	cb.from_prefix_len = colon - ref - 1;
	cb.to_prefix = colon + 1;
	cb.to_prefix_len = len - (colon - ref) - 2;
	for_each_ref(expand_wildcard_ref, &cb);
	return 1;
}

static void set_refspecs(const char **refs, int nr)
{
	if (nr) {
		int i;
		for (i = 0; i < nr; i++) {
			const char *ref = refs[i];
			if (!strcmp("tag", ref)) {
				char *tag;
				int len;
				if (nr <= ++i)
					die("tag shorthand without <tag>");
				len = strlen(refs[i]) + 11;
				tag = xmalloc(len);
				strcpy(tag, "refs/tags/");
				strcat(tag, refs[i]);
				ref = tag;
			}
			else if (wildcard_ref(ref))
				continue;
			add_refspec(ref);
		}
	}
	expand_refspecs();
}

static int do_push(const char *repo)
