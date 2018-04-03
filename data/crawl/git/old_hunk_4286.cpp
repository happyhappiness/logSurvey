		if ($pass) {
			$pass = $self->_scramble($pass);
		} else {
			open(H,$ENV{'HOME'}."/.cvspass") and do {
				# :pserver:cvs@mea.tmt.tele.fi:/cvsroot/zmailer Ah<Z
				while (<H>) {
					chomp;
					s/^\/\d+\s+//;
					my ($w,$p) = split(/\s/,$_,2);
					if ($w eq $rr or $w eq $rr2) {
						$pass = $p;
						last;
					}
				}
			};
			$pass = "A" unless $pass;
		}

		my ($s, $rep);