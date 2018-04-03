	item->util = id;
	fprintf(stderr, "Forgot resolution for %s\n", path);
	return 0;
}

int rerere_forget(struct pathspec *pathspec)