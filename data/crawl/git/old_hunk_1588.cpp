	if (index < suc->failed_clones_nr) {
		int *p;
		ce = suc->failed_clones[index];
		if (!prepare_to_clone_next_submodule(ce, child, suc, err))
			die("BUG: ce was a submodule before?");
		p = xmalloc(sizeof(*p));
		*p = suc->current;
		*idx_task_cb = p;