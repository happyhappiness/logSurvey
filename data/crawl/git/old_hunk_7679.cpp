	}
}

sub rebuild {
	my ($self) = @_;
	my $db_path = $self->db_path;
	return if (-e $db_path && ! -z $db_path);
	return unless ::verify_ref($self->refname.'^0');
	if (-f $self->{db_root}) {
		rename $self->{db_root}, $db_path or die
		     "rename $self->{db_root} => $db_path failed: $!\n";
		my ($dir, $base) = ($db_path =~ m#^(.*?)/?([^/]+)$#);
		symlink $base, $self->{db_root} or die
		     "symlink $base => $self->{db_root} failed: $!\n";
		return;
	}
	print "Rebuilding $db_path ...\n";
	my ($log, $ctx) = command_output_pipe("log", '--no-color', $self->refname);
	my $latest;
	my $full_url = $self->full_url;
	remove_username($full_url);
	my $svn_uuid;
	my $c;
	while (<$log>) {
		if ( m{^commit ($::sha1)$} ) {
