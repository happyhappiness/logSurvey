		break;
	case HTTP_MISSING_TARGET:
		show_http_message(&type, &buffer);
		die("repository '%s' not found", url);
	case HTTP_NOAUTH:
		show_http_message(&type, &buffer);
		die("Authentication failed for '%s'", url);
	default:
		show_http_message(&type, &buffer);
		die("unable to access '%s': %s", url, curl_errorstr);
	}

	last= xcalloc(1, sizeof(*last_discovery));
