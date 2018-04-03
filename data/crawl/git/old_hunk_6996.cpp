		base_obj.data = read_sha1_file(d->base.sha1, &type, &base_obj.size);
		if (!base_obj.data)
			continue;
		link_base_data(NULL, &base_obj);

		find_delta_children(&d->base, &first, &last);
