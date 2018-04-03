 	    svn.useSvmProps/) };
 	$use_svm_props = $use_svm_props eq 'true' if $use_svm_props;
 	foreach (grep { s/^svn-remote\.// } command(qw/config -l/)) {
-		if (m!^(.+)\.fetch=\s*(.*)\s*:\s*refs/remotes/(.+)\s*$!) {
-			my ($remote, $local_ref, $remote_ref) = ($1, $2, $3);
+		if (m!^(.+)\.fetch=\s*(.*)\s*:\s*(.+)\s*$!) {
+			my ($remote, $local_ref, $_remote_ref) = ($1, $2, $3);
+			die("svn-remote.$remote: remote ref '$_remote_ref' "
+			    . "must start with 'refs/remotes/'\n")
+				unless $_remote_ref =~ m{^refs/remotes/(.+)};
+			my $remote_ref = $1;
 			$local_ref =~ s{^/}{};
 			$r->{$remote}->{fetch}->{$local_ref} = $remote_ref;
 			$r->{$remote}->{svm} = {} if $use_svm_props;