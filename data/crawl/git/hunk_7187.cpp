 }
 
 sub cmd_blame {
-	my $path = shift;
+	my $path = pop;
 
 	config_pager();
 	run_pager();
 
-	my ($fh, $ctx) = command_output_pipe('blame', @_, $path);
-	while (my $line = <$fh>) {
-		if ($line =~ /^\^?([[:xdigit:]]+)\s/) {
-			my (undef, $rev, undef) = ::cmt_metadata($1);
-			$rev = sprintf('%-10s', $rev);
-			$line =~ s/^\^?[[:xdigit:]]+(\s)/$rev$1/;
+	my ($fh, $ctx, $rev);
+
+	if ($_git_format) {
+		($fh, $ctx) = command_output_pipe('blame', @_, $path);
+		while (my $line = <$fh>) {
+			if ($line =~ /^\^?([[:xdigit:]]+)\s/) {
+				# Uncommitted edits show up as a rev ID of
+				# all zeros, which we can't look up with
+				# cmt_metadata
+				if ($1 !~ /^0+$/) {
+					(undef, $rev, undef) =
+						::cmt_metadata($1);
+					$rev = '0' if (!$rev);
+				} else {
+					$rev = '0';
+				}
+				$rev = sprintf('%-10s', $rev);
+				$line =~ s/^\^?[[:xdigit:]]+(\s)/$rev$1/;
+			}
+			print $line;
+		}
+	} else {
+		($fh, $ctx) = command_output_pipe('blame', '-p', @_, 'HEAD',
+						  '--', $path);
+		my ($sha1);
+		my %authors;
+		while (my $line = <$fh>) {
+			if ($line =~ /^([[:xdigit:]]{40})\s\d+\s\d+/) {
+				$sha1 = $1;
+				(undef, $rev, undef) = ::cmt_metadata($1);
+				$rev = '0' if (!$rev);
+			}
+			elsif ($line =~ /^author (.*)/) {
+				$authors{$rev} = $1;
+				$authors{$rev} =~ s/\s/_/g;
+			}
+			elsif ($line =~ /^\t(.*)$/) {
+				printf("%6s %10s %s\n", $rev, $authors{$rev}, $1);
+			}
 		}
-		print $line;
 	}
 	command_close_pipe($fh, $ctx);
 }