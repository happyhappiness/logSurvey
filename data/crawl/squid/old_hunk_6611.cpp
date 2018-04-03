    }
}

#if 0				/* moved to httpHeader */
void
httpReplyHeaderStats(StoreEntry * entry)
{
    http_server_cc_t i;
    http_hdr_misc_t j;
    storeAppendPrintf(entry, "HTTP Reply Headers:\n");
    storeAppendPrintf(entry, "       Headers parsed: %d\n",
	ReplyHeaderStats.parsed);
    for (j = HDR_AGE; j < HDR_MISC_END; j++)
	storeAppendPrintf(entry, "%21.21s: %d\n",
	    HttpHdrMiscStr[j],
	    ReplyHeaderStats.misc[j]);
    for (i = CC_PUBLIC; i < CC_ENUM_END; i++)
	storeAppendPrintf(entry, "Cache-Control %s: %d\n",
	    HttpServerCCStr[i],
	    ReplyHeaderStats.cc[i]);
}
#endif

void
httpInit(void)
{
}

static void
httpAbort(void *data)
{
