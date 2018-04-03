	case HTTP_OK:
		break;
	case HTTP_MISSING_TARGET:
		show_http_message(&type, &buffer);
		die("repository '%s' not found", url);
	case HTTP_NOAUTH:
		show_http_message(&type, &buffer);
		die("Authentication failed");