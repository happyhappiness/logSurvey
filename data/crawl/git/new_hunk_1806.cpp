	strbuf_release(&sb);
	return ret;
}

struct files_reflog_iterator {
	struct ref_iterator base;

	struct dir_iterator *dir_iterator;
	struct object_id oid;
};

static int files_reflog_iterator_advance(struct ref_iterator *ref_iterator)
{
	struct files_reflog_iterator *iter =
		(struct files_reflog_iterator *)ref_iterator;
	struct dir_iterator *diter = iter->dir_iterator;
	int ok;

	while ((ok = dir_iterator_advance(diter)) == ITER_OK) {
		int flags;

		if (!S_ISREG(diter->st.st_mode))
			continue;
		if (diter->basename[0] == '.')
			continue;
		if (ends_with(diter->basename, ".lock"))
			continue;

		if (read_ref_full(diter->relative_path, 0,
				  iter->oid.hash, &flags)) {
			error("bad ref for %s", diter->path.buf);
			continue;
		}

		iter->base.refname = diter->relative_path;
		iter->base.oid = &iter->oid;
		iter->base.flags = flags;
		return ITER_OK;
	}

	iter->dir_iterator = NULL;
	if (ref_iterator_abort(ref_iterator) == ITER_ERROR)
		ok = ITER_ERROR;
	return ok;
}

static int files_reflog_iterator_peel(struct ref_iterator *ref_iterator,
				   struct object_id *peeled)
{
	die("BUG: ref_iterator_peel() called for reflog_iterator");
}

static int files_reflog_iterator_abort(struct ref_iterator *ref_iterator)
{
	struct files_reflog_iterator *iter =
		(struct files_reflog_iterator *)ref_iterator;
	int ok = ITER_DONE;

	if (iter->dir_iterator)
		ok = dir_iterator_abort(iter->dir_iterator);

	base_ref_iterator_free(ref_iterator);
	return ok;
}

static struct ref_iterator_vtable files_reflog_iterator_vtable = {
	files_reflog_iterator_advance,
	files_reflog_iterator_peel,
	files_reflog_iterator_abort
};

struct ref_iterator *files_reflog_iterator_begin(void)
{
	struct files_reflog_iterator *iter = xcalloc(1, sizeof(*iter));
	struct ref_iterator *ref_iterator = &iter->base;

	base_ref_iterator_init(ref_iterator, &files_reflog_iterator_vtable);
	iter->dir_iterator = dir_iterator_begin(git_path("logs"));
	return ref_iterator;
}

int for_each_reflog(each_ref_fn fn, void *cb_data)
{
	return do_for_each_ref_iterator(files_reflog_iterator_begin(),
					fn, cb_data);
}

static int ref_update_reject_duplicates(struct string_list *refnames,
