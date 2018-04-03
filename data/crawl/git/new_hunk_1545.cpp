
static int add_one_reference(struct string_list_item *item, void *cb_data)
{
	struct strbuf err = STRBUF_INIT;
	struct strbuf sb = STRBUF_INIT;
	char *ref_git = compute_alternate_path(item->string, &err);

	if (!ref_git)
		die("%s", err.buf);

	strbuf_addf(&sb, "%s/objects", ref_git);
	add_to_alternates_file(sb.buf);

	free(ref_git);
	strbuf_release(&err);
	strbuf_release(&sb);
	return 0;
}

