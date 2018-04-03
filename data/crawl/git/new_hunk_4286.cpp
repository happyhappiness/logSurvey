		if ($pass) {
			$pass = $self->_scramble($pass);
		} else {
			my @cvspass = ([$ENV{'HOME'}."/.cvspass", qr/\s/],
				       [$ENV{'HOME'}."/.cvs/cvspass", qr/=/]);
			my @loc = ();
			foreach my $cvspass (@cvspass) {
				my $p = find_password_entry($cvspass, $rr, $rr2);
				if ($p) {
					push @loc, $cvspass->[0];
					$pass = $p;
				}
			}

			if (1 < @loc) {
				die("Multiple cvs password files have ".
				    "entries for CVSROOT $opt_d: @loc");
			} elsif (!$pass) {
				$pass = "A";
			}
		}

		my ($s, $rep);