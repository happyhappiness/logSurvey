		return 1;

	while (result) {
		printf("%s\n", oid_to_hex(&result->item->object.oid));
		result = result->next;
	}
	return 0;
