	case HTTP_OK:
		break;
	case HTTP_MISSING_TARGET:
		show_http_message(&type, &buffer);
		die("%s not found: did you run git update-server-info on the"
		    " server?", refs_url);
	case HTTP_NOAUTH: