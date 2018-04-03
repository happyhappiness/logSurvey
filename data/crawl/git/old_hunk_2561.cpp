			/* See if it is really trivial. */
			git_committer_info(IDENT_STRICT);
			printf(_("Trying really trivial in-index merge...\n"));
			if (!read_tree_trivial(common->item->object.sha1,
					       head_commit->object.sha1,
					       remoteheads->item->object.sha1)) {
				ret = merge_trivial(head_commit, remoteheads);
				goto done;
			}
