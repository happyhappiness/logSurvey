 currently it is simply the command name but in future the context might
 have more complicated structure.
 
+C<PIPE_IN> and C<PIPE_OUT> may be C<undef> if they have been closed prior to
+calling this function.  This may be useful in a query-response type of
+commands where caller first writes a query and later reads response, eg:
+
+	my ($pid, $in, $out, $ctx) = $r->command_bidi_pipe('cat-file --batch-check');
+	print $out "000000000\n";
+	close $out;
+	while (<$in>) { ... }
+	$r->command_close_bidi_pipe($pid, $in, undef, $ctx);
+
+This idiom may prevent potential dead locks caused by data sent to the output
+pipe not being flushed and thus not reaching the executed command.
+
 =cut
 
 sub command_close_bidi_pipe {
 	local $?;
 	my ($self, $pid, $in, $out, $ctx) = _maybe_self(@_);
-	_cmd_close($ctx, $in, $out);
+	_cmd_close($ctx, (grep { defined } ($in, $out)));
 	waitpid $pid, 0;
 	if ($? >> 8) {
 		throw Git::Error::Command($ctx, $? >>8);