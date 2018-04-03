						      &sb.final_buf_size);

		if (!sb.final_buf)
			die(_("cannot read blob %s for path %s"),
			    sha1_to_hex(o->blob_sha1),
			    path);
	}
