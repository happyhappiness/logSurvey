	my $use_svm_props = eval { command_oneline(qw/config --bool
	    svn.useSvmProps/) };
	$use_svm_props = $use_svm_props eq 'true' if $use_svm_props;
	my $svn_refspec = qr{\s*/?(.*?)\s*:\s*(.+?)\s*};
	foreach (grep { s/^svn-remote\.// } command(qw/config -l/)) {
		if (m!^(.+)\.fetch=$svn_refspec$!) {
			my ($remote, $local_ref, $remote_ref) = ($1, $2, $3);
			die("svn-remote.$remote: remote ref '$remote_ref' "
			    . "must start with 'refs/'\n")
				unless $remote_ref =~ m{^refs/};
			$r->{$remote}->{fetch}->{$local_ref} = $remote_ref;
			$r->{$remote}->{svm} = {} if $use_svm_props;
		} elsif (m!^(.+)\.usesvmprops=\s*(.*)\s*$!) {
			$r->{$1}->{svm} = {};
		} elsif (m!^(.+)\.url=\s*(.*)\s*$!) {
			$r->{$1}->{url} = $2;
		} elsif (m!^(.+)\.(branches|tags)=$svn_refspec$!) {
			my ($remote, $t, $local_ref, $remote_ref) =
			                                     ($1, $2, $3, $4);
			die("svn-remote.$remote: remote ref '$remote_ref' ($t) "
			    . "must start with 'refs/'\n")
				unless $remote_ref =~ m{^refs/};
			my $rs = {
			    t => $t,
			    remote => $remote,
			    path => Git::SVN::GlobSpec->new($local_ref),
			    ref => Git::SVN::GlobSpec->new($remote_ref) };
			if (length($rs->{ref}->{right}) != 0) {
				die "The '*' glob character must be the last ",
				    "character of '$remote_ref'\n";
			}
			push @{ $r->{$remote}->{$t} }, $rs;
		}
	}

