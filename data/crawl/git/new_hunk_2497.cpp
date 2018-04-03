{
	for ( ; list; list = list->next) {
		const char *format = list->next ? format_cur : format_last;
		printf(format, oid_to_hex(&list->item->object.oid));
	}
}

