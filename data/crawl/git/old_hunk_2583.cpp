		common = shift_tree_object(head, common, o->subtree_shift);
	}

	if (sha_eq(common->object.sha1, merge->object.sha1)) {
		output(o, 0, _("Already up-to-date!"));
		*result = head;
		return 1;
