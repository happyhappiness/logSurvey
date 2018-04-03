		conn->defer.n, conn->defer.until);
	}
	storeAppendPrintf(s, "uri %s\n", http->uri);
	storeAppendPrintf(s, "out.offset %d, out.size %d\n",
	    http->out.offset, http->out.size);
	storeAppendPrintf(s, "req_sz %d\n", http->req_sz);