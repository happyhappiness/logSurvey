	error_html(buf);
	return 1;
    }
    l = snprintf(buf, 1024,
	"GET cache_object://%s/%s HTTP/1.0\r\n"
	"Accept: */*\r\n"
	"\r\n",
	req->hostname,
	req->action);
    write(s, buf, l);
    return read_reply(s, req);
}

