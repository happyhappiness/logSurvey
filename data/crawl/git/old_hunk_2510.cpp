	if (code != 0) {
		if (show(o, 4) || o->call_depth)
			die(_("merging of trees %s and %s failed"),
			    sha1_to_hex(head->object.sha1),
			    sha1_to_hex(merge->object.sha1));
		else
			exit(128);
	}
