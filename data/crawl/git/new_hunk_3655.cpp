		case REV_TREE_OLD:
		case REV_TREE_DIFFERENT:
			tree_changed = 1;
			continue;
		}
		die("bad tree compare for commit %s", sha1_to_hex(commit->object.sha1));
	}
	if (tree_changed)
		return;
	commit->object.flags |= TREESAME;
}
