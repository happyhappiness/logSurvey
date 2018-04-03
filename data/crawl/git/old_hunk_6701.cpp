	unlink $gs->{index};
}

sub cmd_find_rev {
	my $revision_or_hash = shift or die "SVN or git revision required ",
	                                    "as a command-line argument\n";
