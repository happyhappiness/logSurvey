			 * Force shutdown and restart if another blob requires filtering.
			 */
			error("external filter '%s' failed", cmd);
			subprocess_stop(&subprocess_map, &entry->subprocess);
			free(entry);
		}
	} else {