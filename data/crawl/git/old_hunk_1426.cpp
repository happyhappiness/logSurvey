		common = shift_tree_object(head, common, o->subtree_shift);
	}

	if (sha_eq(common->object.oid.hash, merge->object.oid.hash)) {
		output(o, 0, _("Already up-to-date!"));
		*result = head;
		return 1;
