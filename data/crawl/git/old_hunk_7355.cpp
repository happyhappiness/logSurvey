		int i, max;

		max = get_max_object_index();
		for (i = 0; i < max; i++) {
			struct object * obj = get_indexed_object(i);
			const char *name;
			if (!obj)
				continue;
			if (!data.name_only)
				printf("%s ", sha1_to_hex(obj->sha1));
			name = get_rev_name(obj);
			if (name)
				printf("%s\n", name);
			else if (allow_undefined)
				printf("undefined\n");
			else
				die("cannot describe '%s'", sha1_to_hex(obj->sha1));
		}
	} else {
		int i;
		for (i = 0; i < revs.nr; i++) {
			const char *name;
			if (!data.name_only)
				printf("%s ", revs.objects[i].name);
			name = get_rev_name(revs.objects[i].item);
			if (name)
				printf("%s\n", name);
			else if (allow_undefined)
				printf("undefined\n");
			else
				die("cannot describe '%s'", sha1_to_hex(revs.objects[i].item->sha1));
		}
	}

	return 0;