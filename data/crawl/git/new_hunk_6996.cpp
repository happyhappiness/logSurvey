		base_obj.data = read_sha1_file(d->base.sha1, &type, &base_obj.size);
		if (!base_obj.data)
			continue;

		if (check_sha1_signature(d->base.sha1, base_obj.data,
				base_obj.size, typename(type)))
			die("local object %s is corrupt", sha1_to_hex(d->base.sha1));
		base_obj.obj = append_obj_to_pack(d->base.sha1, base_obj.data,
			base_obj.size, type);
		link_base_data(NULL, &base_obj);

		find_delta_children(&d->base, &first, &last);
