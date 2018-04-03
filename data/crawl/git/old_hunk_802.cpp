			     const char *path)
{
	if (!o->show_all_errors)
		return error(ERRORMSG(o, e), path);

	/*
	 * Otherwise, insert in a list for future display by
