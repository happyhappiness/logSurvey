		tempfile->on_list = 1;
	} else if (tempfile->filename.len) {
		/* This shouldn't happen, but better safe than sorry. */
		BUG("prepare_tempfile_object called for improperly-reset object");
	}
}

