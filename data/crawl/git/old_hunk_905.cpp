		map {
			system('sh', '-c', $editor.' "$@"', $editor, $_);
			if (($? & 127) || ($? >> 8)) {
				die("the editor exited uncleanly, aborting everything");
			}
		} @_;
	} else {
		system('sh', '-c', $editor.' "$@"', $editor, @_);
		if (($? & 127) || ($? >> 8)) {
			die("the editor exited uncleanly, aborting everything");
		}
	}
}