	$git_avatar = '';
}

# custom error handler: 'die <message>' is Internal Server Error
sub handle_errors_html {
	my $msg = shift; # it is already HTML escaped

	# to avoid infinite loop where error occurs in die_error,
	# change handler to default handler, disabling handle_errors_html
	set_message("Error occured when inside die_error:\n$msg");

	# you cannot jump out of die_error when called as error handler;
	# the subroutine set via CGI::Carp::set_message is called _after_
	# HTTP headers are already written, so it cannot write them itself
	die_error(undef, undef, $msg, -error_handler => 1, -no_http_header => 1);
}
set_message(\&handle_errors_html);

# dispatch
if (!defined $action) {
	if (defined $hash) {
