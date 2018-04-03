			     git_user_agent_sanitized());
		strbuf_release(&symref_info);
	} else {
		packet_write(1, "%s %s\n", oid_to_hex(oid), refname_nons);
	}
	capabilities = NULL;
	if (!peel_ref(refname, peeled.hash))
		packet_write(1, "%s %s^{}\n", oid_to_hex(&peeled), refname_nons);
	return 0;
}
