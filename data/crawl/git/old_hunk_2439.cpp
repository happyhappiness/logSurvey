	assert(!state->msg);
	msg = strstr(buffer, "\n\n");
	if (!msg)
		die(_("unable to parse commit %s"), sha1_to_hex(commit->object.sha1));
	state->msg = xstrdup(msg + 2);
	state->msg_len = strlen(state->msg);
}
