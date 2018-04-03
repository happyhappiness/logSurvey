			else if (!strcmp(arg, "--cached") ||
				 !strcmp(arg, "--staged")) {
				add_head_to_pending(&rev);
				if (!rev.pending.nr) {
					struct tree *tree;
					tree = lookup_tree((const unsigned char*)EMPTY_TREE_SHA1_BIN);
					add_pending_object(&rev, &tree->object, "HEAD");
				}
				break;
			}
		}
