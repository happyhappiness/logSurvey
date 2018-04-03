		}
	}
	if (defined $project) {
		printf('<link rel="alternate" title="%s log RSS feed" '.
		       'href="%s" type="application/rss+xml" />'."\n",
		       esc_param($project), href(action=>"rss"));
		printf('<link rel="alternate" title="%s log RSS feed (no merges)" '.
		       'href="%s" type="application/rss+xml" />'."\n",
		       esc_param($project), href(action=>"rss",
		                                 extra_options=>"--no-merges"));
		printf('<link rel="alternate" title="%s log Atom feed" '.
		       'href="%s" type="application/atom+xml" />'."\n",
		       esc_param($project), href(action=>"atom"));
		printf('<link rel="alternate" title="%s log Atom feed (no merges)" '.
		       'href="%s" type="application/atom+xml" />'."\n",
		       esc_param($project), href(action=>"atom",
		                                 extra_options=>"--no-merges"));
	} else {
		printf('<link rel="alternate" title="%s projects list" '.
		       'href="%s" type="text/plain; charset=utf-8"/>'."\n",
		       $site_name, href(project=>undef, action=>"project_index"));
		printf('<link rel="alternate" title="%s projects feeds" '.
		       'href="%s" type="text/x-opml"/>'."\n",
		       $site_name, href(project=>undef, action=>"opml"));
	}
	if (defined $favicon) {
		print qq(<link rel="shortcut icon" href="$favicon" type="image/png"/>\n);
	}

	print "</head>\n" .
