
		result = read_sha1_file(oid.hash, &type, &size);
		if (!result)
			return error(_("the necessary postimage %s for "
				       "'%s' cannot be read"),
				     patch->new_sha1_prefix, name);
		clear_image(img);
		img->buf = result;
