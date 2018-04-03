		sort_string_list(&list);
		for (i = 0; i < list.nr; i++) {
			struct string_list_item *item = list.items + i;
			printf("%s%s%s\n", item->string,
				verbose ? "\t" : "",
				verbose && item->util ?
					(const char *)item->util : "");
		}
	}
	return result;