	printf("summary %s\n", ci.summary);
	if (suspect->commit->object.flags & UNINTERESTING)
		printf("boundary\n");
	return 1;
}

