
	if (depth == 0 && shallows.nr == 0)
		return;
	if (depth > 0)
		deepen(depth, &shallows);
	else
		if (shallows.nr > 0) {
			int i;
			for (i = 0; i < shallows.nr; i++)