	l_item->e = e;
	l_item->value_index = e->value_list.nr - 1;

	if (cf) {
		kv_info->filename = strintern(cf->name);
		kv_info->linenr = cf->linenr;
	} else {
