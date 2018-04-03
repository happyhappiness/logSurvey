			print '<link rel="stylesheet" type="text/css" href="'.esc_url($stylesheet).'"/>'."\n";
		}
	}
	print_feed_meta()
		if ($status eq '200 OK');
	if (defined $favicon) {
		print qq(<link rel="shortcut icon" href=").esc_url($favicon).qq(" type="image/png" />\n);
	}