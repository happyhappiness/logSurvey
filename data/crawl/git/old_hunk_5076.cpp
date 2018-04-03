		}

		return o->gently ? -1 :
			error(ERRORMSG(o, ERROR_WOULD_LOSE_UNTRACKED), ce->name, action);
	}
	return 0;
}
static int verify_absent(struct cache_entry *ce, const char *action,
			 struct unpack_trees_options *o)
{
	if (!o->skip_sparse_checkout && will_have_skip_worktree(ce, o))
		return 0;
	return verify_absent_1(ce, action, o, ERRORMSG(o, ERROR_WOULD_LOSE_UNTRACKED));
}

static int verify_absent_sparse(struct cache_entry *ce, const char *action,
			 struct unpack_trees_options *o)
{
	return verify_absent_1(ce, action, o, ERRORMSG(o, ERROR_WOULD_LOSE_ORPHANED));
}

static int merged_entry(struct cache_entry *merge, struct cache_entry *old,
