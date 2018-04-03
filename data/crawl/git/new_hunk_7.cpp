
	check_mergetags(commit, argc, argv);

	if (write_sha1_file(buf.buf, buf.len, commit_type, new_oid.hash))
		die(_("could not write replacement commit for: '%s'"), old_ref);

	strbuf_release(&buf);

	if (!oidcmp(&old_oid, &new_oid))
		return error("new commit is the same as the old one: '%s'", oid_to_hex(&old_oid));

	return replace_object_oid(old_ref, &old_oid, "replacement", &new_oid, force);
}

int cmd_replace(int argc, const char **argv, const char *prefix)