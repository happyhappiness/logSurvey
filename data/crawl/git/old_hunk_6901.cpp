	    svn.useSvmProps/) };
	$use_svm_props = $use_svm_props eq 'true' if $use_svm_props;
	foreach (grep { s/^svn-remote\.// } command(qw/config -l/)) {
		if (m!^(.+)\.fetch=\s*(.*)\s*:\s*refs/remotes/(.+)\s*$!) {
			my ($remote, $local_ref, $remote_ref) = ($1, $2, $3);
			$local_ref =~ s{^/}{};
			$r->{$remote}->{fetch}->{$local_ref} = $remote_ref;
			$r->{$remote}->{svm} = {} if $use_svm_props;