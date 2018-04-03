	free(data);
	*status_p = -1;
	error(_("corrupt binary patch at line %d: %.*s"),
	      linenr-1, llen-1, buffer);
	return NULL;
}

