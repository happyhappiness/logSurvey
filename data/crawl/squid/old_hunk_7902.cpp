     int request_type_id;
{
    debug(20, 5, "storeGenerateKey: type=%d %s\n", request_type_id, url);
    if (request_type_id == REQUEST_OP_POST) {
	sprintf(key_temp_buffer, "/post/%s", url);
	return key_temp_buffer;
    }
    if (request_type_id == REQUEST_OP_HEAD) {
	sprintf(key_temp_buffer, "/head/%s", url);
	return key_temp_buffer;
    }
    return url;
}

/*
 * Add a new object to the cache.
 * 
