 	while(<F>) {
 		$message .=  $_;
 		if (/^(Signed-off-by|Cc): (.*)$/i) {
-			next if ($suppress_cc{'sob'});
 			chomp;
-			my $c = $2;
+			my ($what, $c) = ($1, $2);
 			chomp $c;
-			next if ($c eq $sender and $suppress_cc{'self'});
+			if ($c eq $sender) {
+				next if ($suppress_cc{'self'});
+			} else {
+				next if $suppress_cc{'sob'} and $what =~ /Signed-off-by/i;
+				next if $suppress_cc{'bodycc'} and $what =~ /Cc/i;
+			}
 			push @cc, $c;
-			printf("(sob) Adding cc: %s from line '%s'\n",
+			printf("(body) Adding cc: %s from line '%s'\n",
 				$c, $_) unless $quiet;
 		}
 	}
