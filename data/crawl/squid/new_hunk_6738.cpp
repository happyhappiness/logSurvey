	error_html(buf);
	return 1;
    }
    l = snprintf(buf, sizeof(buf),
	"GET cache_object://%s/%s HTTP/1.0\r\n"
	"Accept: */*\r\n"
	"%s" /* Authentication info or nothing */
	"\r\n",
	req->hostname,
	req->action,
	make_auth_header(req));
    write(s, buf, l);
    debug(1) fprintf(stderr, "wrote request: '%s'\n", buf);
    return read_reply(s, req);
}

