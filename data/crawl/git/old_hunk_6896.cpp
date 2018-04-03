		if (entry->no_try_delta)
			continue;

		if (!entry->preferred_base)
			nr_deltas++;

		delta_list[n++] = entry;
	}
