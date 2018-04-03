	storeAppendPrintf(entry, "%21.21s: %d\n",
	    HttpHdrMiscStr[j],
	    ReplyHeaderStats.misc[j]);
    for (i = CC_PUBLIC; i < CC_ENUM_END; i++)
	storeAppendPrintf(entry, "Cache-Control %s: %d\n",
	    HttpServerCCStr[i],
	    ReplyHeaderStats.cc[i]);
