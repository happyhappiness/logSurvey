			ret = HTTP_OK;
		else if (missing_target(&results))
			ret = HTTP_MISSING_TARGET;
		else
			ret = HTTP_ERROR;
	} else {
		error("Unable to start HTTP request for %s", url);
