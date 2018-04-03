	    (substr($file, 0, $lastlen) eq $last) &&
	    ($suffix = substr($file, $lastlen)) !~ /^[a-z0-9]/i) {
		if (defined $known_suffix && $suffix eq $known_suffix) {
			print "Skipping $file with backup suffix '$known_suffix'.\n";
			$skip = 1;
		} else {
			my $answer = ask("Do you really want to send $file? (y|N): ",
					 valid_re => qr/^(?:y|n)/i,
					 default => 'n');
			$skip = ($answer ne 'y');
