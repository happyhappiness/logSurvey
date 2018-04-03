	 * write it at all.
	 */
	if (opts->action == REPLAY_PICK && !opts->no_commit && (res == 0 || res == 1))
		update_ref(NULL, "CHERRY_PICK_HEAD", commit->object.sha1, NULL,
			   REF_NODEREF, UPDATE_REFS_DIE_ON_ERR);
	if (opts->action == REPLAY_REVERT && ((opts->no_commit && res == 0) || res == 1))
		update_ref(NULL, "REVERT_HEAD", commit->object.sha1, NULL,
			   REF_NODEREF, UPDATE_REFS_DIE_ON_ERR);

	if (res) {
		error(opts->action == REPLAY_REVERT
		      ? _("could not revert %s... %s")
		      : _("could not apply %s... %s"),
		      find_unique_abbrev(commit->object.sha1, DEFAULT_ABBREV),
		      msg.subject);
		print_advice(res == 1, opts);
		rerere(opts->allow_rerere_auto);
