			/* See if it is really trivial. */
			git_committer_info(IDENT_STRICT);
			printf(_("Trying really trivial in-index merge...\n"));
			if (!read_tree_trivial(common->item->object.oid.hash,
					       head_commit->object.oid.hash,
					       remoteheads->item->object.oid.hash)) {
				ret = merge_trivial(head_commit, remoteheads);
				goto done;
			}
