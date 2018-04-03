{
	void *ret;

	if (unsigned_mult_overflows(nmemb, size))
		die("data too large to fit into virtual memory space");

	memory_limit_check(size * nmemb, 0);
	ret = calloc(nmemb, size);
	if (!ret && (!nmemb || !size))