		return 1;

	while (result) {
		printf("%s\n", sha1_to_hex(result->item->object.sha1));
		result = result->next;
	}
	return 0;
