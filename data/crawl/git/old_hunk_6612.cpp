
static void rename_branch(const char *oldname, const char *newname, int force)
{
	char oldref[PATH_MAX], newref[PATH_MAX], logmsg[PATH_MAX*2 + 100];
	unsigned char sha1[20];
	char oldsection[PATH_MAX], newsection[PATH_MAX];

	if (!oldname)
		die("cannot rename the current branch while not on any.");

	if (snprintf(oldref, sizeof(oldref), "refs/heads/%s", oldname) > sizeof(oldref))
		die("Old branchname too long");

	if (check_ref_format(oldref))
		die("Invalid branch name: %s", oldref);

	if (snprintf(newref, sizeof(newref), "refs/heads/%s", newname) > sizeof(newref))
		die("New branchname too long");

	if (check_ref_format(newref))
		die("Invalid branch name: %s", newref);

	if (resolve_ref(newref, sha1, 1, NULL) && !force)
		die("A branch named '%s' already exists.", newname);

	snprintf(logmsg, sizeof(logmsg), "Branch: renamed %s to %s",
		 oldref, newref);

	if (rename_ref(oldref, newref, logmsg))
		die("Branch rename failed");

	/* no need to pass logmsg here as HEAD didn't really move */
	if (!strcmp(oldname, head) && create_symref("HEAD", newref, NULL))
		die("Branch renamed to %s, but HEAD is not updated!", newname);

	snprintf(oldsection, sizeof(oldsection), "branch.%s", oldref + 11);
	snprintf(newsection, sizeof(newsection), "branch.%s", newref + 11);
	if (git_config_rename_section(oldsection, newsection) < 0)
		die("Branch is renamed, but update of config-file failed");
}

static int opt_parse_with_commit(const struct option *opt, const char *arg, int unset)