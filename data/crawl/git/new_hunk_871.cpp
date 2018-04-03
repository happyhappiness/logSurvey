	strbuf_addf(sb, ",prefix:%d)", prefixlen);
}

static inline int get_literal_global(void)
{
	static int literal = -1;

	if (literal < 0)
		literal = git_env_bool(GIT_LITERAL_PATHSPECS_ENVIRONMENT, 0);

	return literal;
}

static inline int get_glob_global(void)
{
	static int glob = -1;

	if (glob < 0)
		glob = git_env_bool(GIT_GLOB_PATHSPECS_ENVIRONMENT, 0);

	return glob;
}

static inline int get_noglob_global(void)
{
	static int noglob = -1;

	if (noglob < 0)
		noglob = git_env_bool(GIT_NOGLOB_PATHSPECS_ENVIRONMENT, 0);

	return noglob;
}

static inline int get_icase_global(void)
{
	static int icase = -1;

	if (icase < 0)
		icase = git_env_bool(GIT_ICASE_PATHSPECS_ENVIRONMENT, 0);

	return icase;
}

static int get_global_magic(int element_magic)
{
	int global_magic = 0;

	if (get_literal_global())
		global_magic |= PATHSPEC_LITERAL;

	/* --glob-pathspec is overridden by :(literal) */
	if (get_glob_global() && !(element_magic & PATHSPEC_LITERAL))
		global_magic |= PATHSPEC_GLOB;

	if (get_glob_global() && get_noglob_global())
		die(_("global 'glob' and 'noglob' pathspec settings are incompatible"));

	if (get_icase_global())
		global_magic |= PATHSPEC_ICASE;

	if ((global_magic & PATHSPEC_LITERAL) &&
	    (global_magic & ~PATHSPEC_LITERAL))
		die(_("global 'literal' pathspec setting is incompatible "
		      "with all other global pathspec settings"));

	/* --noglob-pathspec adds :(literal) _unless_ :(glob) is specified */
	if (get_noglob_global() && !(element_magic & PATHSPEC_GLOB))
		global_magic |= PATHSPEC_LITERAL;

	return global_magic;
}

/*
 * Take an element of a pathspec and check for magic signatures.
 * Append the result to the prefix. Return the magic bitmap.
