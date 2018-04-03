 	      "\n</div>\n";
 }
 
+sub print_local_time {
+	my %date = @_;
+	if ($date{'hour_local'} < 6) {
+		printf(" (<span class=\"atnight\">%02d:%02d</span> %s)",
+			$date{'hour_local'}, $date{'minute_local'}, $date{'tz_local'});
+	} else {
+		printf(" (%02d:%02d %s)",
+			$date{'hour_local'}, $date{'minute_local'}, $date{'tz_local'});
+	}
+}
+
+# Outputs the author name and date in long form
 sub git_print_authorship {
 	my $co = shift;
+	my %opts = @_;
+	my $tag = $opts{-tag} || 'div';
 
 	my %ad = parse_date($co->{'author_epoch'}, $co->{'author_tz'});
-	print "<div class=\"author_date\">" .
+	print "<$tag class=\"author_date\">" .
 	      esc_html($co->{'author_name'}) .
 	      " [$ad{'rfc2822'}";
-	if ($ad{'hour_local'} < 6) {
-		printf(" (<span class=\"atnight\">%02d:%02d</span> %s)",
-		       $ad{'hour_local'}, $ad{'minute_local'}, $ad{'tz_local'});
-	} else {
-		printf(" (%02d:%02d %s)",
-		       $ad{'hour_local'}, $ad{'minute_local'}, $ad{'tz_local'});
+	print_local_time(%ad) if ($opts{-localtime});
+	print "]</$tag>\n";
+}
+
+# Outputs table rows containing the full author or committer information,
+# in the format expected for 'commit' view (& similia).
+# Parameters are a commit hash reference, followed by the list of people
+# to output information for. If the list is empty it defalts to both
+# author and committer.
+sub git_print_authorship_rows {
+	my $co = shift;
+	# too bad we can't use @people = @_ || ('author', 'committer')
+	my @people = @_;
+	@people = ('author', 'committer') unless @people;
+	foreach my $who (@people) {
+		my %wd = parse_date($co->{"${who}_epoch"}, $co->{"${who}_tz"});
+		print "<tr><td>$who</td><td>" . esc_html($co->{$who}) . "</td></tr>\n".
+		      "<tr>" .
+		      "<td></td><td> $wd{'rfc2822'}";
+		print_local_time(%wd);
+		print "</td>" .
+		      "</tr>\n";
 	}
-	print "]</div>\n";
 }
 
 sub git_print_page_path {
