
int error_resolve_conflict(const char *me)
{
	error("%s is not possible because you have unmerged files.", me);
	if (advice_resolve_conflict)
		/*
		 * Message used both when 'git commit' fails and when
