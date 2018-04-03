{
	unsigned flags = SUBMODULE_MOVE_HEAD_DRY_RUN;
	const struct submodule *sub = submodule_from_ce(ce);

	if (!sub)
		return 0;

	if (o->reset)
		flags |= SUBMODULE_MOVE_HEAD_FORCE;

	if (submodule_move_head(ce->name, old_id, new_id, flags))
		return o->gently ? -1 :
				   add_rejected_path(o, ERROR_WOULD_LOSE_SUBMODULE, ce->name);
	return 0;
}

static void reload_gitmodules_file(struct index_state *index,
