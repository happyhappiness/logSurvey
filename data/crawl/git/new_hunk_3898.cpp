	/* Pick one of them (we know there at least is one) */
	for (i = 0; i < want_obj.nr; i++) {
		o = want_obj.objects[i].item;
		if (!is_our_ref(o))
			die("git upload-pack: not our ref %s",
			    sha1_to_hex(o->sha1));
	}
