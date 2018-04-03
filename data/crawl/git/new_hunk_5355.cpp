	return 0;
}

static int string_list_add_one_ref(const char *path, const unsigned char *sha1,
				   int flag, void *cb)
{
	struct string_list *refs = cb;
	if (!unsorted_string_list_has_string(refs, path))
		string_list_append(path, refs);
	return 0;
}

void string_list_add_refs_by_glob(struct string_list *list, const char *glob)
{
	if (has_glob_specials(glob)) {
		for_each_glob_ref(string_list_add_one_ref, glob, list);
	} else {
		unsigned char sha1[20];
		if (get_sha1(glob, sha1))
			warning("notes ref %s is invalid", glob);
		if (!unsorted_string_list_has_string(list, glob))
			string_list_append(glob, list);
	}
}

void string_list_add_refs_from_colon_sep(struct string_list *list,
					 const char *globs)
{
	struct strbuf globbuf = STRBUF_INIT;
	struct strbuf **split;
	int i;

	strbuf_addstr(&globbuf, globs);
	split = strbuf_split(&globbuf, ':');

	for (i = 0; split[i]; i++) {
		if (!split[i]->len)
			continue;
		if (split[i]->buf[split[i]->len-1] == ':')
			strbuf_setlen(split[i], split[i]->len-1);
		string_list_add_refs_by_glob(list, split[i]->buf);
	}

	strbuf_list_free(split);
	strbuf_release(&globbuf);
}

static int string_list_add_refs_from_list(struct string_list_item *item,
					  void *cb)
{
	struct string_list *list = cb;
	string_list_add_refs_by_glob(list, item->string);
	return 0;
}

static int notes_display_config(const char *k, const char *v, void *cb)
{
	int *load_refs = cb;

	if (*load_refs && !strcmp(k, "notes.displayref")) {
		if (!v)
			config_error_nonbool(k);
		string_list_add_refs_by_glob(&display_notes_refs, v);
	}

	return 0;
}

static const char *default_notes_ref(void)
{
	const char *notes_ref = NULL;
	if (!notes_ref)
		notes_ref = getenv(GIT_NOTES_REF_ENVIRONMENT);
	if (!notes_ref)
		notes_ref = notes_ref_name; /* value of core.notesRef config */
	if (!notes_ref)
		notes_ref = GIT_NOTES_DEFAULT_REF;
	return notes_ref;
}

void init_notes(struct notes_tree *t, const char *notes_ref,
		combine_notes_fn combine_notes, int flags)
{
