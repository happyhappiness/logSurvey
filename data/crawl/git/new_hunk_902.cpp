
	my @addresses = ();
	open my $fh, "-|", "$cmd \Q$file\E"
	    or die sprintf(__("(%s) Could not execute '%s'"), $prefix, $cmd);
	while (my $address = <$fh>) {
		$address =~ s/^\s*//g;
		$address =~ s/\s*$//g;
		$address = sanitize_address($address);
		next if ($address eq $sender and $suppress_cc{'self'});
		push @addresses, $address;
		printf(__("(%s) Adding %s: %s from: '%s'\n"),
		       $prefix, $what, $address, $cmd) unless $quiet;
		}
	close $fh
	    or die sprintf(__("(%s) failed to close pipe to '%s'"), $prefix, $cmd);
	return @addresses;
}

