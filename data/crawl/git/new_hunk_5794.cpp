	}
	print "<div class=\"title_text\">\n" .
	      "<table class=\"object_header\">\n";
	git_print_authorship_rows(\%co);
	print "<tr><td>commit</td><td class=\"sha1\">$co{'id'}</td></tr>\n";
	print "<tr>" .
	      "<td>tree</td>" .
