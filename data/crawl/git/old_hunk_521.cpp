		if (parse_feature_request(features, "include-tag"))
			use_include_tag = 1;

		o = parse_object(sha1_buf);
		if (!o) {
			packet_write_fmt(1,
					 "ERR upload-pack: not our ref %s",
					 sha1_to_hex(sha1_buf));
			die("git upload-pack: not our ref %s",
			    sha1_to_hex(sha1_buf));
		}
		if (!(o->flags & WANTED)) {
			o->flags |= WANTED;