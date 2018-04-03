			      sha1_to_hex(it->sha1));
			return 1;
		}
		mark_object_reachable(obj);
		obj->used = 1;
		if (obj->type != OBJ_TREE)
			err |= objerror(obj, "non-tree in cache-tree");
