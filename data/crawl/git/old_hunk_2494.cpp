		if (tail <= bufptr + parent_entry_len + 1 ||
		    get_sha1_hex(bufptr + 7, parent.hash) ||
		    bufptr[parent_entry_len] != '\n')
			return error("bad parents in commit %s", sha1_to_hex(item->object.sha1));
		bufptr += parent_entry_len + 1;
		/*
		 * The clone is shallow if nr_parent < 0, and we must
