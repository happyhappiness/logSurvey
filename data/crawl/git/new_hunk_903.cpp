	    (substr($file, 0, $lastlen) eq $last) &&
	    ($suffix = substr($file, $lastlen)) !~ /^[a-z0-9]/i) {
		if (defined $known_suffix && $suffix eq $known_suffix) {
			printf(__("Skipping %s with backup suffix '%s'.\n"), $file, $known_suffix);
			$skip = 1;
		} else {
			# TRANSLATORS: please keep "[y|N]" as is.
			my $answer = ask(sprintf(__("Do you really want to send %s? [y|N]: "), $file),
					 valid_re => qr/^(?:y|n)/i,
					 default => 'n');
			$skip = ($answer ne 'y');
