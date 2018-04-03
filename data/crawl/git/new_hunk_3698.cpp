		return DIFF_STATUS_MODIFIED;
}

static void warn_add_would_remove(const char *path)
{
	warning(_("In Git 2.0, 'git add <pathspec>...' will also update the\n"
		  "index for paths removed from the working tree that match\n"
		  "the given pathspec. If you want to 'add' only changed\n"
		  "or newly created paths, say 'git add --no-all <pathspec>...'"
		  " instead.\n\n"
		  "'%s' would be removed from the index without --no-all."),
		path);
}

static void update_callback(struct diff_queue_struct *q,
			    struct diff_options *opt, void *cbdata)
{
