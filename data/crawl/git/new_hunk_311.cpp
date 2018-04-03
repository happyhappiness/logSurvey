	}

	if (oid_eq(&common->object.oid, &merge->object.oid)) {
		output(o, 0, _("Already up to date!"));
		*result = head;
		return 1;
	}
