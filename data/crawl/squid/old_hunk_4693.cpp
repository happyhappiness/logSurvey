        debug(11,3)("ServerStateData::startIcap fails: broken service\n");
        return false;
    }
    assert(NULL == icap);
    icap = new ICAPClientRespmodPrecache(service);
    return true;
}

#endif
