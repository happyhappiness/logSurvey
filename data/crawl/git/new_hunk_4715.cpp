		if (resolve_ref(oldref.buf, sha1, 1, NULL))
			recovery = 1;
		else
			die(_("Invalid branch name: '%s'"), oldname);
	}

	if (strbuf_check_branch_ref(&newref, newname))
		die(_("Invalid branch name: '%s'"), newname);

	if (resolve_ref(newref.buf, sha1, 1, NULL) && !force)
		die(_("A branch named '%s' already exists."), newref.buf + 11);

	strbuf_addf(&logmsg, "Branch: renamed %s to %s",
		 oldref.buf, newref.buf);

	if (rename_ref(oldref.buf, newref.buf, logmsg.buf))
		die(_("Branch rename failed"));
	strbuf_release(&logmsg);

	if (recovery)
		warning(_("Renamed a misnamed branch '%s' away"), oldref.buf + 11);

	/* no need to pass logmsg here as HEAD didn't really move */
	if (!strcmp(oldname, head) && create_symref("HEAD", newref.buf, NULL))
		die(_("Branch renamed to %s, but HEAD is not updated!"), newname);

	strbuf_addf(&oldsection, "branch.%s", oldref.buf + 11);
	strbuf_release(&oldref);
	strbuf_addf(&newsection, "branch.%s", newref.buf + 11);
	strbuf_release(&newref);
	if (git_config_rename_section(oldsection.buf, newsection.buf) < 0)
		die(_("Branch is renamed, but update of config-file failed"));
	strbuf_release(&oldsection);
	strbuf_release(&newsection);
}
