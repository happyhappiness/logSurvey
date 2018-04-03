		hold_locked_index(&lock, 1);
		clean = merge_recursive(&o, head,
				remoteheads->item, reversed, &result);
		if (active_cache_changed &&
		    write_locked_index(&the_index, &lock, COMMIT_LOCK))
			die (_("unable to write %s"), get_index_file());
