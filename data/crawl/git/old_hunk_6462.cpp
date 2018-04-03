	while(<F>) {
		$message .=  $_;
		if (/^(Signed-off-by|Cc): (.*)$/i) {
			next if ($suppress_cc{'sob'});
			chomp;
			my $c = $2;
			chomp $c;
			next if ($c eq $sender and $suppress_cc{'self'});
			push @cc, $c;
			printf("(sob) Adding cc: %s from line '%s'\n",
				$c, $_) unless $quiet;
		}
	}
