	if (errno == ENOENT)
		return 0;
	return o->gently ? -1 :
		error(ERRORMSG(o, error_type), ce->name);
}

static int verify_uptodate(struct cache_entry *ce,
			   struct unpack_trees_options *o)
{
	if (!o->skip_sparse_checkout && will_have_skip_worktree(ce, o))
		return 0;
	return verify_uptodate_1(ce, o, ERROR_NOT_UPTODATE_FILE);
}

static int verify_uptodate_sparse(struct cache_entry *ce,
				  struct unpack_trees_options *o)
{
	return verify_uptodate_1(ce, o, ERROR_SPARSE_NOT_UPTODATE_FILE);
}

static void invalidate_ce_path(struct cache_entry *ce, struct unpack_trees_options *o)
