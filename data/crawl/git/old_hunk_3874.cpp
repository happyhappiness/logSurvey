currently it is simply the command name but in future the context might
have more complicated structure.

=cut

sub command_close_bidi_pipe {
	local $?;
	my ($self, $pid, $in, $out, $ctx) = _maybe_self(@_);
	_cmd_close($ctx, $in, $out);
	waitpid $pid, 0;
	if ($? >> 8) {
		throw Git::Error::Command($ctx, $? >>8);