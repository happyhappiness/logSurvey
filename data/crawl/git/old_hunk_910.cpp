				next if $suppress_cc{'bodycc'} and $what =~ /Cc/i;
			}
			push @cc, $c;
			printf("(body) Adding cc: %s from line '%s'\n",
				$c, $_) unless $quiet;
		}
	}