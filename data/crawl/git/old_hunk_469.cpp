			 * Force shutdown and restart if another blob requires filtering.
			 */
			error("external filter '%s' failed", cmd);
			kill_multi_file_filter(&cmd_process_map, &entry->subprocess);
			free(entry);
		}
	} else {