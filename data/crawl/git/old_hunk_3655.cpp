		case REV_TREE_OLD:
		case REV_TREE_DIFFERENT:
			tree_changed = 1;
			pp = &parent->next;
			continue;
		}
		die("bad tree compare for commit %s", sha1_to_hex(commit->object.sha1));
	}
	if (tree_changed && !tree_same)
		return;
	commit->object.flags |= TREESAME;
}
