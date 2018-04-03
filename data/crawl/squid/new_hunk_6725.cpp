	}
    }
    storeBuffer(e);
#if 0				/* old code */
    storeAppendPrintf(e, "HTTP/1.0 200 Gatewaying\r\n");
    reply->code = 200;
    reply->version = 1.0;
