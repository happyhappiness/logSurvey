static CURL *get_curl_handle(void)
{
	CURL *result = curl_easy_init();
	long allowed_protocols = 0;

	if (!result)
		die("curl_easy_init failed");
