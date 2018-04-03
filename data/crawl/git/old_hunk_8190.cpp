		printf('<link rel="alternate" title="%s log RSS feed" '.
		       'href="%s" type="application/rss+xml" />'."\n",
		       esc_param($project), href(action=>"rss"));
		printf('<link rel="alternate" title="%s log Atom feed" '.
		       'href="%s" type="application/atom+xml" />'."\n",
		       esc_param($project), href(action=>"atom"));
	} else {
		printf('<link rel="alternate" title="%s projects list" '.
		       'href="%s" type="text/plain; charset=utf-8"/>'."\n",
