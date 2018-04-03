		error("%s: not a commit", refname);
	default_refs++;
	obj->used = 1;
	mark_reachable(obj, REACHABLE);

	return 0;
}
