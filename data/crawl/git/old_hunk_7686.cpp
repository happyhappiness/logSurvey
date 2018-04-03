{
	struct git_var *ptr;
	for(ptr = git_vars; ptr->read; ptr++) {
		printf("%s=%s\n", ptr->name, ptr->read(0));
	}
}

