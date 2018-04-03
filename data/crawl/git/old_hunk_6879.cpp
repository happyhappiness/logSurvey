			reason = "add/add";
			o_sha = (unsigned char *)null_sha1;
		}
		output(2, "Auto-merged %s", path);
		o.path = a.path = b.path = (char *)path;
		hashcpy(o.sha1, o_sha);
		o.mode = o_mode;