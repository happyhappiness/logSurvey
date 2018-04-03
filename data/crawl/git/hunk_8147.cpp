 		}
 	}
 	close F;
+
+	if ($cc_cmd ne "") {
+		open(F, "$cc_cmd $t |")
+			or die "(cc-cmd) Could not execute '$cc_cmd'";
+		while(<F>) {
+			my $c = $_;
+			$c =~ s/^\s*//g;
+			$c =~ s/\n$//g;
+			push @cc, $c;
+			printf("(cc-cmd) Adding cc: %s from: '%s'\n",
+				$c, $cc_cmd) unless $quiet;
+		}
+		close F
+			or die "(cc-cmd) failed to close pipe to '$cc_cmd'";
+	}
+
 	if (defined $author) {
 		$message = "From: $author\n\n$message";
 	}
 
-
 	send_message();
 
 	# set up for the next message