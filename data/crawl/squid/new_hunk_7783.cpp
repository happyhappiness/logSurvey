    switch (method) {
    case METHOD_GET:
	return url;
	/* NOTREACHED */
	break;
    case METHOD_POST:
	sprintf(key_temp_buffer, "/post/%s", url);
	return key_temp_buffer;
	/* NOTREACHED */
	break;
    case METHOD_HEAD:
	sprintf(key_temp_buffer, "/head/%s", url);
	return key_temp_buffer;
	/* NOTREACHED */
	break;
    case METHOD_CONNECT:
	sprintf(key_temp_buffer, "/connect/%s", url);
	return key_temp_buffer;
	/* NOTREACHED */
	break;
    default:
	fatal_dump("storeGeneratePublicKey: Unsupported request method");
