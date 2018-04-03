			return 1;
		}
		obj->used = 1;
		mark_object_reachable(obj);
		if (obj->type != OBJ_TREE)
			err |= objerror(obj, "non-tree in cache-tree");
