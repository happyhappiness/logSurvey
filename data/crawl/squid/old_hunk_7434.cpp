void
httpReplyHeaderStats(StoreEntry * entry)
{
    storeAppendPrintf(entry, open_bracket);
    storeAppendPrintf(entry, "{HTTP Reply Headers}\n");
    storeAppendPrintf(entry, "{Headers parsed: %d}\n",
	ReplyHeaderStats.parsed);
    storeAppendPrintf(entry, "{          Date: %d}\n",
	ReplyHeaderStats.date);
    storeAppendPrintf(entry, "{ Last-Modified: %d}\n",
	ReplyHeaderStats.lm);
    storeAppendPrintf(entry, "{       Expires: %d}\n",
	ReplyHeaderStats.exp);
    storeAppendPrintf(entry, "{  Content-Type: %d}\n",
	ReplyHeaderStats.ctype);
    storeAppendPrintf(entry, "{Content-Length: %d}\n",
	ReplyHeaderStats.clen);
    storeAppendPrintf(entry, "{Cache-Control Private: %d}\n",
	ReplyHeaderStats.cc.private);
    storeAppendPrintf(entry, "{Cache-Control Cachable: %d}\n",
	ReplyHeaderStats.cc.cachable);
    storeAppendPrintf(entry, "{Cache-Control Nocache: %d}\n",
	ReplyHeaderStats.cc.nocache);
    storeAppendPrintf(entry, close_bracket);
}
