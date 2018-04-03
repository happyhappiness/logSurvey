	return wantarray ? %res : \%res;
}

# parse line of git-ls-tree output
sub parse_ls_tree_line ($;%) {
	my $line = shift;
