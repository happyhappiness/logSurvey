		if (obj) {
			obj->used = 1;
			mark_object_reachable(obj);
		}
	}
}
