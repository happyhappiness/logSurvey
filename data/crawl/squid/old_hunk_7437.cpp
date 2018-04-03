	ReplyHeaderStats.ctype);
    storeAppendPrintf(entry, "{Content-Length: %d}\n",
	ReplyHeaderStats.clen);
    storeAppendPrintf(entry, close_bracket);
}
