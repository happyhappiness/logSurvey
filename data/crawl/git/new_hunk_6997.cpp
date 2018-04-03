				resolve_delta(child, &base_obj, type);
		}

		unlink_base_data(&base_obj);
		display_progress(progress, nr_resolved_deltas);
	}