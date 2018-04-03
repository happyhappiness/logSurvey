		 */
		o = lookup_object(sha1_buf);
		if (!o || !(o->flags & OUR_REF))
			die("git upload-pack: not our ref %s",
			    sha1_to_hex(sha1_buf));
		if (!(o->flags & WANTED)) {
			o->flags |= WANTED;
			add_object_array(o, NULL, &want_obj);