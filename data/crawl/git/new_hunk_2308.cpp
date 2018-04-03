		return sb.buf;
	if (uname(&uts) < 0)
		die_errno(_("failed to get kernel name and information"));
	strbuf_addf(&sb, "Location %s, system %s", get_git_work_tree(),
		    uts.sysname);
	return sb.buf;
}

static int ident_in_untracked(const struct untracked_cache *uc)
{
	/*
	 * Previous git versions may have saved many NUL separated
	 * strings in the "ident" field, but it is insane to manage
	 * many locations, so just take care of the first one.
	 */

	return !strcmp(uc->ident.buf, get_ident_string());
}

static void set_untracked_ident(struct untracked_cache *uc)
{
	strbuf_reset(&uc->ident);
	strbuf_addstr(&uc->ident, get_ident_string());

	/*
	 * This strbuf used to contain a list of NUL separated
	 * strings, so save NUL too for backward compatibility.
	 */
	strbuf_addch(&uc->ident, 0);
}

