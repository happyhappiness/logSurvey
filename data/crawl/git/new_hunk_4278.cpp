
static int update_local_ref(struct ref *ref,
			    const char *remote,
			    struct strbuf *display)
{
	struct commit *current = NULL, *updated;
	enum object_type type;
	struct branch *current_branch = branch_get(NULL);
	const char *pretty_ref = prettify_refname(ref->name);

	type = sha1_object_info(ref->new_sha1, NULL);
	if (type < 0)
		die(_("object %s not found"), sha1_to_hex(ref->new_sha1));

	if (!hashcmp(ref->old_sha1, ref->new_sha1)) {
		if (verbosity > 0)
			strbuf_addf(display, "= %-*s %-*s -> %s",
				    TRANSPORT_SUMMARY_WIDTH,
				    _("[up to date]"), REFCOL_WIDTH,
				    remote, pretty_ref);
		return 0;
	}

