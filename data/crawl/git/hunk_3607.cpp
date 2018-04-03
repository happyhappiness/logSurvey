 	my $pushed;
 	for my $refspec (@refsspecs) {
 		my ($force, $local, $remote) = $refspec =~ /^(\+)?([^:]*):([^:]*)$/
-		    or die("Invalid refspec for push. Expected <src>:<dst> or +<src>:<dst>");
+		    or die("Invalid refspec for push. Expected <src>:<dst> or +<src>:<dst>\n");
 		if ($force) {
 			print STDERR "Warning: forced push not allowed on a MediaWiki.\n";
 		}
