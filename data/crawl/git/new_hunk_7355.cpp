		int i, max;

		max = get_max_object_index();
		for (i = 0; i < max; i++)
			show_name(get_indexed_object(i), NULL,
				  always, allow_undefined, data.name_only);
	} else {
		int i;
		for (i = 0; i < revs.nr; i++)
			show_name(revs.objects[i].item, revs.objects[i].name,
				  always, allow_undefined, data.name_only);
	}

	return 0;