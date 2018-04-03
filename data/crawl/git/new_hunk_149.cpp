	}

	if (commit_tree_extended(msg->buf, msg->len, tree.hash, parents,
				 oid->hash, author, opts->gpg_sign, extra)) {
		res = error(_("failed to write commit object"));
		goto out;
	}
