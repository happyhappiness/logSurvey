		ret = 0;
		break;
	case HTTP_ERROR:
		error("unable to access '%s': %s", url, curl_errorstr);
	default:
		ret = -1;
	}
