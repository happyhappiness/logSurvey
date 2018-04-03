		if (!ok_to_replace)
			return error("'%s' appears as both a file and as a directory",
				     ce->name);
		pos = index_name_pos(istate, ce->name, ce->ce_flags);
		pos = -pos-1;
	}
	return pos + 1;
