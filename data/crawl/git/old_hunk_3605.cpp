		} elsif ($line eq "\n") {
			return @refs;
		} else {
			die("Invalid command in a '$cmd' batch: ". $_);
		}
	}
	return;
