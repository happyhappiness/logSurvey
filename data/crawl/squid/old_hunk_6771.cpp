	reply->last_modified = ftpState->mdtm;
    }
    storeAppendPrintf(e, "\r\n");
    storeBufferFlush(e);
    reply->hdr_sz = e->mem_obj->inmem_hi;
    storeTimestampsSet(e);
