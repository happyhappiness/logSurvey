	if (!resolves_to || strcmp(resolves_to, d->refname))
		return 0;

	printf(d->msg_fmt, refname);
	return 0;
}

void warn_dangling_symref(const char *msg_fmt, const char *refname)
{
	struct warn_if_dangling_data data = { refname, msg_fmt };
	for_each_rawref(warn_if_dangling_symref, &data);
}

