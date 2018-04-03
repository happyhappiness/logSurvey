	strbuf_release(&sb);
	return ret;
}
/*
 * Call fn for each reflog in the namespace indicated by name.  name
 * must be empty or end with '/'.  Name will be used as a scratch
 * space, but its contents will be restored before return.
 */
static int do_for_each_reflog(struct strbuf *name, each_ref_fn fn, void *cb_data)
{
	DIR *d = opendir(git_path("logs/%s", name->buf));
	int retval = 0;
	struct dirent *de;
	int oldlen = name->len;

	if (!d)
		return name->len ? errno : 0;

	while ((de = readdir(d)) != NULL) {
		struct stat st;

		if (de->d_name[0] == '.')
			continue;
		if (ends_with(de->d_name, ".lock"))
			continue;
		strbuf_addstr(name, de->d_name);
		if (stat(git_path("logs/%s", name->buf), &st) < 0) {
			; /* silently ignore */
		} else {
			if (S_ISDIR(st.st_mode)) {
				strbuf_addch(name, '/');
				retval = do_for_each_reflog(name, fn, cb_data);
			} else {
				struct object_id oid;

				if (read_ref_full(name->buf, 0, oid.hash, NULL))
					error("bad ref for %s", name->buf);
				else
					retval = fn(name->buf, &oid, 0, cb_data);
			}
			if (retval)
				break;
		}
		strbuf_setlen(name, oldlen);
	}
	closedir(d);
	return retval;
}

int for_each_reflog(each_ref_fn fn, void *cb_data)
{
	int retval;
	struct strbuf name;
	strbuf_init(&name, PATH_MAX);
	retval = do_for_each_reflog(&name, fn, cb_data);
	strbuf_release(&name);
	return retval;
}

static int ref_update_reject_duplicates(struct string_list *refnames,
