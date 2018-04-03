			}
			printf("\n");
		}
cleanup_states:
		/* NEEDSWORK: free remote */
		path_list_clear(&states.new, 0);
		path_list_clear(&states.stale, 0);
