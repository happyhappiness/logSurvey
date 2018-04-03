		return;
	prefix = " (";
	while (decoration) {
		printf("%s%s", prefix, decoration->name);
		prefix = ", ";
		decoration = decoration->next;
	}