	const char *email_end = strrchr(committer, '>');
	struct strbuf buf = STRBUF_INIT;
	if (!email_start || !email_end || email_start > email_end - 1)
		die(_("Could not extract email from committer identity."));
	strbuf_addf(&buf, "%s.%lu.git.%.*s", base,
		    (unsigned long) time(NULL),
		    (int)(email_end - email_start - 1), email_start + 1);
