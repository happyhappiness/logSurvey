			       abbrev, detached, remote_prefix);

	free_ref_list(&ref_list);
}

static void rename_branch(const char *oldname, const char *newname, int force)
