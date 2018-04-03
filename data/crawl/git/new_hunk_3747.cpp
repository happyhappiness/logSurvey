		die("Authentication failed for '%s'", url);
	default:
		show_http_message(&type, &buffer);
		die("unable to access '%s': %s", url, curl_errorstr);
	}

	last= xcalloc(1, sizeof(*last_discovery));