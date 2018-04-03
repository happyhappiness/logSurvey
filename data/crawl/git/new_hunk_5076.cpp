		}

		return o->gently ? -1 :
			error(ERRORMSG(o, error_type), ce->name);
	}
	return 0;
}
static int verify_absent(struct cache_entry *ce,
			 enum unpack_trees_error_types error_type,
			 struct unpack_trees_options *o)
{
	if (!o->skip_sparse_checkout && will_have_skip_worktree(ce, o))
		return 0;
	return verify_absent_1(ce, error_type, o);
}

static int verify_absent_sparse(struct cache_entry *ce,
			 enum unpack_trees_error_types error_type,
			 struct unpack_trees_options *o)
{
	enum unpack_trees_error_types orphaned_error = error_type;
	if (orphaned_error == ERROR_WOULD_LOSE_UNTRACKED_OVERWRITTEN)
		orphaned_error = ERROR_WOULD_LOSE_ORPHANED_OVERWRITTEN;

	return verify_absent_1(ce, orphaned_error, o);
}

static int merged_entry(struct cache_entry *merge, struct cache_entry *old,
