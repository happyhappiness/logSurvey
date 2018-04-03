		return 1;

	for_each_string_list_item(item, &suc.projectlines)
		fprintf(stdout, "%s", item->string);

	return 0;
}