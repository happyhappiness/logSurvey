	i = read_directory(&d, ce->name, pathbuf, namelen+1, NULL);
	if (i)
		return o->gently ? -1 :
			error("Updating '%s' would lose untracked files in it",
			      ce->name);
	free(pathbuf);
	return cnt;
}
