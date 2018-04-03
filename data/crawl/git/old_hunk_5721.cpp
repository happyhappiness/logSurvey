	my $use_svm_props = eval { command_oneline(qw/config --bool
	    svn.useSvmProps/) };
	$use_svm_props = $use_svm_props eq 'true' if $use_svm_props;
	foreach (grep { s/^svn-remote\.// } command(qw/config -l/)) {
		if (m!^(.+)\.fetch=\s*(.*)\s*:\s*(.+)\s*$!) {
			my ($remote, $local_ref, $_remote_ref) = ($1, $2, $3);
			die("svn-remote.$remote: remote ref '$_remote_ref' "
			    . "must start with 'refs/remotes/'\n")
				unless $_remote_ref =~ m{^refs/remotes/(.+)};
			my $remote_ref = $1;
			$local_ref =~ s{^/}{};
			$r->{$remote}->{fetch}->{$local_ref} = $remote_ref;
			$r->{$remote}->{svm} = {} if $use_svm_props;
		} elsif (m!^(.+)\.usesvmprops=\s*(.*)\s*$!) {
			$r->{$1}->{svm} = {};
		} elsif (m!^(.+)\.url=\s*(.*)\s*$!) {
			$r->{$1}->{url} = $2;
		} elsif (m!^(.+)\.(branches|tags)=
		           (.*):refs/remotes/(.+)\s*$/!x) {
			my ($p, $g) = ($3, $4);
			my $rs = {
			    t => $2,
			    remote => $1,
			    path => Git::SVN::GlobSpec->new($p),
			    ref => Git::SVN::GlobSpec->new($g) };
			if (length($rs->{ref}->{right}) != 0) {
				die "The '*' glob character must be the last ",
				    "character of '$g'\n";
			}
			push @{ $r->{$1}->{$2} }, $rs;
		}
	}

