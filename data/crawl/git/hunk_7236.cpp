 		}
 	}
 	if (defined $project) {
-		printf('<link rel="alternate" title="%s log RSS feed" '.
-		       'href="%s" type="application/rss+xml" />'."\n",
-		       esc_param($project), href(action=>"rss"));
-		printf('<link rel="alternate" title="%s log RSS feed (no merges)" '.
-		       'href="%s" type="application/rss+xml" />'."\n",
-		       esc_param($project), href(action=>"rss",
-		                                 extra_options=>"--no-merges"));
-		printf('<link rel="alternate" title="%s log Atom feed" '.
-		       'href="%s" type="application/atom+xml" />'."\n",
-		       esc_param($project), href(action=>"atom"));
-		printf('<link rel="alternate" title="%s log Atom feed (no merges)" '.
-		       'href="%s" type="application/atom+xml" />'."\n",
-		       esc_param($project), href(action=>"atom",
-		                                 extra_options=>"--no-merges"));
+		my %href_params = get_feed_info();
+		if (!exists $href_params{'-title'}) {
+			$href_params{'-title'} = 'log';
+		}
+
+		foreach my $format qw(RSS Atom) {
+			my $type = lc($format);
+			my %link_attr = (
+				'-rel' => 'alternate',
+				'-title' => "$project - $href_params{'-title'} - $format feed",
+				'-type' => "application/$type+xml"
+			);
+
+			$href_params{'action'} = $type;
+			$link_attr{'-href'} = href(%href_params);
+			print "<link ".
+			      "rel=\"$link_attr{'-rel'}\" ".
+			      "title=\"$link_attr{'-title'}\" ".
+			      "href=\"$link_attr{'-href'}\" ".
+			      "type=\"$link_attr{'-type'}\" ".
+			      "/>\n";
+
+			$href_params{'extra_options'} = '--no-merges';
+			$link_attr{'-href'} = href(%href_params);
+			$link_attr{'-title'} .= ' (no merges)';
+			print "<link ".
+			      "rel=\"$link_attr{'-rel'}\" ".
+			      "title=\"$link_attr{'-title'}\" ".
+			      "href=\"$link_attr{'-href'}\" ".
+			      "type=\"$link_attr{'-type'}\" ".
+			      "/>\n";
+		}
+
 	} else {
 		printf('<link rel="alternate" title="%s projects list" '.
-		       'href="%s" type="text/plain; charset=utf-8"/>'."\n",
+		       'href="%s" type="text/plain; charset=utf-8" />'."\n",
 		       $site_name, href(project=>undef, action=>"project_index"));
 		printf('<link rel="alternate" title="%s projects feeds" '.
-		       'href="%s" type="text/x-opml"/>'."\n",
+		       'href="%s" type="text/x-opml" />'."\n",
 		       $site_name, href(project=>undef, action=>"opml"));
 	}
 	if (defined $favicon) {
-		print qq(<link rel="shortcut icon" href="$favicon" type="image/png"/>\n);
+		print qq(<link rel="shortcut icon" href="$favicon" type="image/png" />\n);
 	}
 
 	print "</head>\n" .
