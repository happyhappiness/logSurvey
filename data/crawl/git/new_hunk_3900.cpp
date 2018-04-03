		return 0;

	if (capabilities)
		packet_write(1, "%s %s%c%s%s%s agent=%s\n",
			     sha1_to_hex(sha1), refname_nons,
			     0, capabilities,
			     allow_tip_sha1_in_want ? " allow-tip-sha1-in-want" : "",
			     stateless_rpc ? " no-done" : "",
			     git_user_agent_sanitized());
	else
