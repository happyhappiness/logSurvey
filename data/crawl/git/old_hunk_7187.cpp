}

sub cmd_blame {
	my $path = shift;

	config_pager();
	run_pager();

	my ($fh, $ctx) = command_output_pipe('blame', @_, $path);
	while (my $line = <$fh>) {
		if ($line =~ /^\^?([[:xdigit:]]+)\s/) {
			my (undef, $rev, undef) = ::cmt_metadata($1);
			$rev = sprintf('%-10s', $rev);
			$line =~ s/^\^?[[:xdigit:]]+(\s)/$rev$1/;
		}
		print $line;
	}
	command_close_pipe($fh, $ctx);
}