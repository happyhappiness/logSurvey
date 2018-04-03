		 */
		if ((apply || check) &&
		    (!patch->is_binary && !metadata_changes(patch)))
			die(_("patch with only garbage at line %d"), state_linenr);
	}

	return offset + hdrsize + patchsize;