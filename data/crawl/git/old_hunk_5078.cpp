	i = read_directory(&d, pathbuf, namelen+1, NULL);
	if (i)
		return o->gently ? -1 :
			error(ERRORMSG(o, not_uptodate_dir), ce->name);
	free(pathbuf);
	return cnt;
}
