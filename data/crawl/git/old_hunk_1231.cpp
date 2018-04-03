			 * apply_patch->check_patch_list->check_patch->
			 * apply_data->apply_fragments->apply_one_fragment
			 */
			if (ws_error_action == die_on_ws_error)
				apply = 0;
		}

		if (apply_verbosely && applied_pos != pos) {
			int offset = applied_pos - pos;
			if (apply_in_reverse)
				offset = 0 - offset;
			fprintf_ln(stderr,
				   Q_("Hunk #%d succeeded at %d (offset %d line).",
