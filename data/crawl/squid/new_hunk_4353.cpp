        return;
    }

    cloneReply();

    /* handle headers */

    if (Config.onoff.log_mime_hdrs) {
	size_t k;

	if ((k = headersEnd(buf, reqofs))) {
	    safe_free(http->al.headers.reply);
	    http->al.headers.reply = (char *)xcalloc(k + 1, 1);
	    xstrncpy(http->al.headers.reply, buf, k);
	}
    }

    holdingBuffer = result;
    processReplyAccess();
    return;
}


