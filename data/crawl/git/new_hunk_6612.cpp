
static void rename_branch(const char *oldname, const char *newname, int force)
{
	struct strbuf oldref = STRBUF_INIT, newref = STRBUF_INIT, logmsg = STRBUF_INIT;
	unsigned char sha1[20];
	struct strbuf oldsection = STRBUF_INIT, newsection = STRBUF_INIT;

	if (!oldname)
		die("cannot rename the current branch while not on any.");

	strbuf_addf(&oldref, "refs/heads/%s", oldname);

	if (check_ref_format(oldref.buf))
		die("Invalid branch name: %s", oldref.buf);

	strbuf_addf(&newref, "refs/heads/%s", newname);

	if (check_ref_format(newref.buf))
		die("Invalid branch name: %s", newref.buf);

	if (resolve_ref(newref.buf, sha1, 1, NULL) && !force)
		die("A branch named '%s' already exists.", newname);

	strbuf_addf(&logmsg, "Branch: renamed %s to %s",
		 oldref.buf, newref.buf);

	if (rename_ref(oldref.buf, newref.buf, logmsg.buf))
		die("Branch rename failed");
	strbuf_release(&logmsg);

	/* no need to pass logmsg here as HEAD didn't really move */
	if (!strcmp(oldname, head) && create_symref("HEAD", newref.buf, NULL))
		die("Branch renamed to %s, but HEAD is not updated!", newname);

	strbuf_addf(&oldsection, "branch.%s", oldref.buf + 11);
	strbuf_release(&oldref);
	strbuf_addf(&newsection, "branch.%s", newref.buf + 11);
	strbuf_release(&newref);
	if (git_config_rename_section(oldsection.buf, newsection.buf) < 0)
		die("Branch is renamed, but update of config-file failed");
	strbuf_release(&oldsection);
	strbuf_release(&newsection);
}

static int opt_parse_with_commit(const struct option *opt, const char *arg, int unset)