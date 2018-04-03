	return ret;
}

int set_worktree_head_symref(const char *gitdir, const char *target)
{
	static struct lock_file head_lock;
	struct ref_lock *lock;
	struct strbuf err = STRBUF_INIT;
	struct strbuf head_path = STRBUF_INIT;
	const char *head_rel;
	int ret;

	strbuf_addf(&head_path, "%s/HEAD", absolute_path(gitdir));
	if (hold_lock_file_for_update(&head_lock, head_path.buf,
				      LOCK_NO_DEREF) < 0) {
		error("%s", err.buf);
		strbuf_release(&err);
		strbuf_release(&head_path);
		return -1;
	}

	/* head_rel will be "HEAD" for the main tree, "worktrees/wt/HEAD" for
	   linked trees */
	head_rel = remove_leading_path(head_path.buf,
				       absolute_path(get_git_common_dir()));
	/* to make use of create_symref_locked(), initialize ref_lock */
	lock = xcalloc(1, sizeof(struct ref_lock));
	lock->lk = &head_lock;
	lock->ref_name = xstrdup(head_rel);
	lock->orig_ref_name = xstrdup(head_rel);

	ret = create_symref_locked(lock, head_rel, target, NULL);

	unlock_ref(lock); /* will free lock */
	strbuf_release(&head_path);
	return ret;
}

int reflog_exists(const char *refname)
{
	struct stat st;