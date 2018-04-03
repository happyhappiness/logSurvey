		oconfig_item_t *item = ci->children + i;
		
		if (strcasecmp(item->key, "Interactive") == 0) {
			if (item->values_num != 1 || item->values[0].type != OCONFIG_TYPE_BOOLEAN ||
					!item->values[0].value.boolean)
				continue;
			do_interactive = 1;
		} else if (strcasecmp(item->key, "ModulePath") == 0) {
			char *dir = NULL;
			PyObject *dir_object;
