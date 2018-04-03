	while(<F>) {
		$message .=  $_;
		if (/^(Signed-off-by|Cc): (.*)$/i) {
			chomp;
			my ($what, $c) = ($1, $2);
			chomp $c;
			if ($c eq $sender) {
				next if ($suppress_cc{'self'});
			} else {
				next if $suppress_cc{'sob'} and $what =~ /Signed-off-by/i;
				next if $suppress_cc{'bodycc'} and $what =~ /Cc/i;
			}
			push @cc, $c;
			printf("(body) Adding cc: %s from line '%s'\n",
				$c, $_) unless $quiet;
		}
	}
