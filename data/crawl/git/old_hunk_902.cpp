
	my @addresses = ();
	open my $fh, "-|", "$cmd \Q$file\E"
	    or die "($prefix) Could not execute '$cmd'";
	while (my $address = <$fh>) {
		$address =~ s/^\s*//g;
		$address =~ s/\s*$//g;
		$address = sanitize_address($address);
		next if ($address eq $sender and $suppress_cc{'self'});
		push @addresses, $address;
		printf("($prefix) Adding %s: %s from: '%s'\n",
		       $what, $address, $cmd) unless $quiet;
		}
	close $fh
	    or die "($prefix) failed to close pipe to '$cmd'";
	return @addresses;
}

