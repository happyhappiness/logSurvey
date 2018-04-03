{
	validate_resume_state(state);

	say(state, stdout, _("Applying: %.*s"), linelen(state->msg), state->msg);

	if (!index_has_changes(NULL)) {
		printf_ln(_("No changes - did you forget to use 'git add'?\n"
