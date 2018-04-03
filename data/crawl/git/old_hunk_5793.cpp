	      "\n</div>\n";
}

sub git_print_authorship {
	my $co = shift;

	my %ad = parse_date($co->{'author_epoch'}, $co->{'author_tz'});
	print "<div class=\"author_date\">" .
	      esc_html($co->{'author_name'}) .
	      " [$ad{'rfc2822'}";
	if ($ad{'hour_local'} < 6) {
		printf(" (<span class=\"atnight\">%02d:%02d</span> %s)",
		       $ad{'hour_local'}, $ad{'minute_local'}, $ad{'tz_local'});
	} else {
		printf(" (%02d:%02d %s)",
		       $ad{'hour_local'}, $ad{'minute_local'}, $ad{'tz_local'});
	}
	print "]</div>\n";
}

sub git_print_page_path {
