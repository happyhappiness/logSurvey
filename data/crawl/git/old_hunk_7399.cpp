			      sha1_to_hex(it->sha1));
			return 1;
		}
		mark_reachable(obj, REACHABLE);
		obj->used = 1;
		if (obj->type != OBJ_TREE)
			err |= objerror(obj, "non-tree in cache-tree");
