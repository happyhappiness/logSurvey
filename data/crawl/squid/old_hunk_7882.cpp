	getMyHostname());
    if (!log_errors)
	return tmp_error_buf;
    CacheInfo->log_append(CacheInfo,
	url,
	"0.0.0.0",
	0,
	ErrorData[index].tag,
	"GET",
	0,
	0);
    return tmp_error_buf;
}
