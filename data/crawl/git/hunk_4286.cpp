 		if ($pass) {
 			$pass = $self->_scramble($pass);
 		} else {
-			open(H,$ENV{'HOME'}."/.cvspass") and do {
-				# :pserver:cvs@mea.tmt.tele.fi:/cvsroot/zmailer Ah<Z
-				while (<H>) {
-					chomp;
-					s/^\/\d+\s+//;
-					my ($w,$p) = split(/\s/,$_,2);
-					if ($w eq $rr or $w eq $rr2) {
-						$pass = $p;
-						last;
-					}
+			my @cvspass = ([$ENV{'HOME'}."/.cvspass", qr/\s/],
+				       [$ENV{'HOME'}."/.cvs/cvspass", qr/=/]);
+			my @loc = ();
+			foreach my $cvspass (@cvspass) {
+				my $p = find_password_entry($cvspass, $rr, $rr2);
+				if ($p) {
+					push @loc, $cvspass->[0];
+					$pass = $p;
 				}
-			};
-			$pass = "A" unless $pass;
+			}
+
+			if (1 < @loc) {
+				die("Multiple cvs password files have ".
+				    "entries for CVSROOT $opt_d: @loc");
+			} elsif (!$pass) {
+				$pass = "A";
+			}
 		}
 
 		my ($s, $rep);