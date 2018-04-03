	strbuf_release(&out);
}

static int show_blob_object(const struct object_id *oid, struct rev_info *rev, const char *obj_name)
{
	struct object_id oidc;
	struct object_context obj_context;
	char *buf;
	unsigned long size;

	fflush(rev->diffopt.file);
	if (!DIFF_OPT_TOUCHED(&rev->diffopt, ALLOW_TEXTCONV) ||
	    !DIFF_OPT_TST(&rev->diffopt, ALLOW_TEXTCONV))
		return stream_blob_to_fd(1, oid->hash, NULL, 0);

	if (get_sha1_with_context(obj_name, 0, oidc.hash, &obj_context))
		die(_("Not a valid object name %s"), obj_name);
	if (!obj_context.path[0] ||
	    !textconv_object(obj_context.path, obj_context.mode, oidc.hash, 1, &buf, &size))
		return stream_blob_to_fd(1, oid->hash, NULL, 0);

	if (!buf)
		die(_("git show %s: bad file"), obj_name);
