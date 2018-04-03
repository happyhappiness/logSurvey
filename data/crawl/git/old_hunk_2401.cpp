			/* See if it is really trivial. */
			git_committer_info(IDENT_STRICT);
			printf(_("Trying really trivial in-index merge...\n"));
			if (!read_tree_trivial(get_object_hash(common->item->object),
					       get_object_hash(head_commit->object),
					       get_object_hash(remoteheads->item->object))) {
				ret = merge_trivial(head_commit, remoteheads);
				goto done;
			}
