		return -1;
	}
	else if (mkdir(git_path_seq_dir(), 0777) < 0)
		return error_errno(_("Could not create sequencer directory %s"),
				   git_path_seq_dir());
	return 0;
}
