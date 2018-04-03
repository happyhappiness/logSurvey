			continue;

		if (check_sha1_signature(d->sha1, base_obj->data,
				base_obj->size, type_name(type)))
			die(_("local object %s is corrupt"), sha1_to_hex(d->sha1));
		base_obj->obj = append_obj_to_pack(f, d->sha1,
					base_obj->data, base_obj->size, type);
