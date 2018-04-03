 			print '<link rel="stylesheet" type="text/css" href="'.esc_url($stylesheet).'"/>'."\n";
 		}
 	}
-	if (defined $project) {
-		my %href_params = get_feed_info();
-		if (!exists $href_params{'-title'}) {
-			$href_params{'-title'} = 'log';
-		}
-
-		foreach my $format qw(RSS Atom) {
-			my $type = lc($format);
-			my %link_attr = (
-				'-rel' => 'alternate',
-				'-title' => esc_attr("$project - $href_params{'-title'} - $format feed"),
-				'-type' => "application/$type+xml"
-			);
-
-			$href_params{'action'} = $type;
-			$link_attr{'-href'} = href(%href_params);
-			print "<link ".
-			      "rel=\"$link_attr{'-rel'}\" ".
-			      "title=\"$link_attr{'-title'}\" ".
-			      "href=\"$link_attr{'-href'}\" ".
-			      "type=\"$link_attr{'-type'}\" ".
-			      "/>\n";
-
-			$href_params{'extra_options'} = '--no-merges';
-			$link_attr{'-href'} = href(%href_params);
-			$link_attr{'-title'} .= ' (no merges)';
-			print "<link ".
-			      "rel=\"$link_attr{'-rel'}\" ".
-			      "title=\"$link_attr{'-title'}\" ".
-			      "href=\"$link_attr{'-href'}\" ".
-			      "type=\"$link_attr{'-type'}\" ".
-			      "/>\n";
-		}
-
-	} else {
-		printf('<link rel="alternate" title="%s projects list" '.
-		       'href="%s" type="text/plain; charset=utf-8" />'."\n",
-		       esc_attr($site_name), href(project=>undef, action=>"project_index"));
-		printf('<link rel="alternate" title="%s projects feeds" '.
-		       'href="%s" type="text/x-opml" />'."\n",
-		       esc_attr($site_name), href(project=>undef, action=>"opml"));
-	}
+	print_feed_meta()
+		if ($status eq '200 OK');
 	if (defined $favicon) {
 		print qq(<link rel="shortcut icon" href=").esc_url($favicon).qq(" type="image/png" />\n);
 	}