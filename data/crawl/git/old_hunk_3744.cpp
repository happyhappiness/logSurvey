		ret = 0;
		break;
	case HTTP_ERROR:
		http_error(url);
	default:
		ret = -1;
	}
