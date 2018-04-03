			} else
				parse_from_existing(b);
		}
	} else if (!get_sha1(from, b->oid.hash)) {
		parse_from_existing(b);
		if (is_null_oid(&b->oid))
			b->delete = 1;
	}
	else
		die("Invalid ref name or SHA1 expression: %s", from);

	if (b->branch_tree.tree && hashcmp(sha1, b->branch_tree.versions[1].oid.hash)) {
		release_tree_content_recursive(b->branch_tree.tree);
		b->branch_tree.tree = NULL;
	}
