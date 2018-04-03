my $editor = $ENV{GIT_EDITOR} || Git::config(@repo, "core.editor") || $ENV{VISUAL} || $ENV{EDITOR} || "vi";
sub do_edit {
	if (defined($multiedit) && !$multiedit) {
		map { system('sh', '-c', $editor.' "$@"', $editor, $_); } @_;
	} else {
		system('sh', '-c', $editor.' "$@"', $editor, @_);
	}
}

