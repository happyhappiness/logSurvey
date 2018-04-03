		}
	}

	if (revs->def == NULL)
		revs->def = def;
	if (revs->show_merge)
		prepare_show_merge(revs);
	if (revs->def && !revs->pending.nr) {
		unsigned char sha1[20];
		struct object *object;
		unsigned mode;
		if (get_sha1_with_mode(revs->def, sha1, &mode))
			die("bad default revision '%s'", revs->def);
		object = get_reference(revs, revs->def, sha1, 0);
		add_pending_object_with_mode(revs, object, revs->def, mode);
	}

	/* Did the user ask for any diff output? Run the diff! */
