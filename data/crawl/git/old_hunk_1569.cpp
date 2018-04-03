		 * empty to us here.
		 */
		if ((state->apply || state->check) &&
		    (!patch->is_binary && !metadata_changes(patch)))
			die(_("patch with only garbage at line %d"), state->linenr);
	}

	return offset + hdrsize + patchsize;
