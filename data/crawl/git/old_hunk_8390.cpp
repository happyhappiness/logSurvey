			struct object * obj = get_indexed_object(i);
			if (!obj)
				continue;
			printf("%s %s\n", sha1_to_hex(obj->sha1), get_rev_name(obj));
		}
	} else {
		int i;
		for (i = 0; i < revs.nr; i++)
			printf("%s %s\n",
				revs.objects[i].name,
				get_rev_name(revs.objects[i].item));
	}

	return 0;