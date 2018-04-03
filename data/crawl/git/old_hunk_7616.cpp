		max = get_max_object_index();
		for (i = 0; i < max; i++) {
			struct object * obj = get_indexed_object(i);
			if (!obj)
				continue;
			if (!data.name_only)
				printf("%s ", sha1_to_hex(obj->sha1));
			printf("%s\n", get_rev_name(obj));
		}
	} else {
		int i;
		for (i = 0; i < revs.nr; i++) {
			if (!data.name_only)
				printf("%s ", revs.objects[i].name);
			printf("%s\n", get_rev_name(revs.objects[i].item));
		}
	}
