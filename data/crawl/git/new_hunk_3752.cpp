		die("Authentication failed for '%s'", url);
	default:
		show_http_message(&type, &buffer);
		http_error(url);
		die("HTTP request failed");
	}
