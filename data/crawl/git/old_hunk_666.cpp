
int refs_verify_refname_available(struct ref_store *refs,
				  const char *refname,
				  const struct string_list *extra,
				  const struct string_list *skip,
				  struct strbuf *err)
{
	return refs->be->verify_refname_available(refs, refname, extra, skip, err);
}

int refs_for_each_reflog(struct ref_store *refs, each_ref_fn fn, void *cb_data)
