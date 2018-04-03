				$sauthor = sanitize_address($author);
				next if $suppress_cc{'author'};
				next if $suppress_cc{'self'} and $sauthor eq $sender;
				printf(__("(mbox) Adding cc: %s from line '%s'\n"),
					$1, $_) unless $quiet;
				push @cc, $1;
			}
			elsif (/^To:\s+(.*)$/i) {
				foreach my $addr (parse_address_line($1)) {
					printf(__("(mbox) Adding to: %s from line '%s'\n"),
						$addr, $_) unless $quiet;
					push @to, $addr;
				}
