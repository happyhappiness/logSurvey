	if (mark_our_ref(refname, sha1, flag, NULL))
		return 0;

	if (capabilities)
		packet_write(1, "%s %s%c%s%s%s agent=%s\n",
			     sha1_to_hex(sha1), refname_nons,
			     0, capabilities,
			     allow_tip_sha1_in_want ? " allow-tip-sha1-in-want" : "",
			     stateless_rpc ? " no-done" : "",
			     git_user_agent_sanitized());
	else
		packet_write(1, "%s %s\n", sha1_to_hex(sha1), refname_nons);
	capabilities = NULL;
	if (!peel_ref(refname, peeled))
		packet_write(1, "%s %s^{}\n", sha1_to_hex(peeled), refname_nons);
	return 0;
}

static void upload_pack(void)
{
	if (advertise_refs || !stateless_rpc) {
		reset_timeout();
		head_ref_namespaced(send_ref, NULL);
		for_each_namespaced_ref(send_ref, NULL);
		packet_flush(1);
	} else {
		head_ref_namespaced(mark_our_ref, NULL);
		for_each_namespaced_ref(mark_our_ref, NULL);
	}
	if (advertise_refs)
		return;
