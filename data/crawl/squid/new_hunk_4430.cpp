                      IpcacheStats.invalid);
    storeAppendPrintf(sentry, "\n\n");
    storeAppendPrintf(sentry, "IP Cache Contents:\n\n");
    storeAppendPrintf(sentry, " %-31.31s %3s %6s %6s  %4s\n",
                      "Hostname",
                      "Flg",
                      "lstref",
                      "TTL",
                      "N(b)");

    for (m = lru_list.head; m; m = m->next) {
        assert( m->next != m );
        ipcacheStatPrint((ipcache_entry *)m->data, sentry);
    }
}

/**
 * Takes two IPAddress arrays and merges them into a single array
 * which is allocated dynamically to fit the number of unique addresses
 *
 \param aaddrs	One list to merge
 \param alen	Size of list aaddrs
 \param baddrs	Other list to merge
 \param alen	Size of list baddrs
 \param out	Combined list of unique addresses (sorted with IPv6 first in IPv6-mode)
 \param outlen	Size of list out
 */
void
ipcacheMergeIPLists(IPAddress *aaddrs, int alen,
                    IPAddress *baddrs, int blen,
                    IPAddress **out, int &outlen )
{
    int fc=0, t=0, c=0;

    IPAddress *ip4ptrs[255];
#if USE_IPV6
    IPAddress *ip6ptrs[255];
#endif
    int num_ip4 = 0;
    int num_ip6 = 0;

    memset(ip4ptrs, 0, sizeof(IPAddress*)*255);
#if USE_IPV6
    memset(ip6ptrs, 0, sizeof(IPAddress*)*255);
#endif

    // for each unique address in list A - grab ptr
    for(t = 0; t < alen; t++) {
        if(aaddrs[t].IsIPv4()) {
            // check against IPv4 pruned list
            for(c = 0; c <= num_ip4; c++) {
                if(ip4ptrs[c] && aaddrs[t] == *(ip4ptrs[c]) ) break; // duplicate.
            }
            if(c > num_ip4) {
                ip4ptrs[num_ip4] = &aaddrs[t];
                num_ip4++;
            }
        }
#if USE_IPV6
        else if(aaddrs[t].IsIPv6()) {
debugs(14,8, HERE << "A[" << t << "]=IPv6 " << aaddrs[t]);
            // check against IPv6 pruned list
            for(c = 0; c <= num_ip6; c++) {
                if(ip6ptrs[c] && aaddrs[t] == *ip6ptrs[c]) break; // duplicate.
            }
            if(c > num_ip6) {
                ip6ptrs[num_ip6] = &aaddrs[t];
                num_ip6++;
            }
        }
#endif
    }

    // for each unique address in list B - grab ptr
    for(t = 0; t < blen; t++) {
        if(baddrs[t].IsIPv4()) {
            // check against IPv4 pruned list
            for(c = 0; c <= num_ip4; c++) {
                if(ip4ptrs[c] && baddrs[t] == *ip4ptrs[c]) break; // duplicate.
            }
            if(c > num_ip4) {
                ip4ptrs[num_ip4] = &baddrs[t];
                num_ip4++;
            }
        }
#if USE_IPV6
        else if(baddrs[t].IsIPv6()) {
            // check against IPv6 pruned list
            for(c = 0; c <= num_ip6; c++) {
                if(ip6ptrs[c] && baddrs[t] == *ip6ptrs[c]) break; // duplicate.
            }
            if(c > num_ip6) {
                ip6ptrs[num_ip6] = &baddrs[t];
                num_ip6++;
            }
        }
#endif
    }

    fc = num_ip6 + num_ip4;

    assert(fc > 0);

    debugs(14, 5, "ipcacheMergeIPLists: Merge " << alen << "+" << blen << " into " << fc << " unique IPs.");

    // copy the old IPs into the new list buffer.
    (*out) = (IPAddress*)xcalloc(fc, sizeof(IPAddress));
    outlen=0;

    assert(out != NULL);

#if USE_IPV6
    /* IPv6 are preferred (tried first) over IPv4 */

    for(int l = 0; outlen < num_ip6; l++, outlen++) {
        (*out)[outlen] = *ip6ptrs[l];
        debugs(14, 5, "ipcacheMergeIPLists:  #" << outlen << " " << (*out)[outlen] );
    }
#endif /* USE_IPV6 */

    for(int l = 0; outlen < num_ip4; l++, outlen++) {
        (*out)[outlen] = *ip4ptrs[l];
        debugs(14, 5, "ipcacheMergeIPLists:  #" << outlen << " " << (*out)[outlen] );
    }

    assert(outlen == fc); // otherwise something broke badly!
}

static void
ipcacheHandleCnameRecurse(const ipcache_addrs *addrs, void *cbdata)
{
    ipcache_entry *i = NULL;
    char *pname = NULL;
    IPAddress *tmpbuf = NULL;
    int fc = 0;
    int ttl = 0;
    generic_cbdata* gcb = (generic_cbdata*)cbdata;
    // count of addrs at parent and child (REQ as .count is a char type!)
    int ccount = 0, pcount = 0;

    debugs(14, 5, "ipcacheHandleCnameRecurse: Handling basic A/AAAA response.");

    /* IFF no CNAME recursion being processed. do nothing. */
    if(cbdata == NULL)
        return;

    gcb->unwrap(&i);
    assert(i != NULL);

    // make sure we are actualy waiting for a CNAME callback to be run.
    assert(i->cname_wait > 0);
    // count this event. its being handled.
    i->cname_wait--;

    pname = (char*)i->hash.key;
    assert(pname != NULL);

    debugs(14, 5, "ipcacheHandleCnameRecurse: Handling CNAME recursion. CBDATA('" << gcb->data << "')='" << pname << "' -> " << std::hex << i);

    if(i == NULL) {
        return; // Parent has expired. Don't merge, just leave for future Ref:
    }

    /* IFF addrs is NULL (Usually an Error or Timeout occured on lookup.) */
    /* Ignore it and HOPE that we got some Additional records to use.     */
    if(addrs == NULL)
        return;

    ccount = (0+ addrs->count);
    pcount = (0+ i->addrs.count);
    ttl = i->expires;

    /* IFF no CNAME results. do none of the processing BUT finish anyway. */
    if(addrs) {

        debugs(14, 5, "ipcacheHandleCnameRecurse: Merge IP Lists for " << pname << " (" << pcount << "+" << ccount << ")");

            /* add new IP records to entry */
        tmpbuf = i->addrs.in_addrs;
        i->addrs.in_addrs = NULL;
        ipcacheMergeIPLists(tmpbuf, pcount, addrs->in_addrs, ccount, &(i->addrs.in_addrs), fc);
        debugs(14,8, HERE << "in=" << tmpbuf << ", out=" << i->addrs.in_addrs );
        assert(tmpbuf);
        safe_free(tmpbuf);

        if( pcount > 0) {
            /* IFF the parent initial lookup was given Additional records with A */
            // clear the 'bad IP mask'
            safe_free(i->addrs.bad_mask);
        }
        // create a new bad IP mask to fit the new size needed.
        if(fc > 0) {
            i->addrs.bad_mask = (unsigned char*)xcalloc(fc, sizeof(unsigned char));
            memset(i->addrs.bad_mask, 0, sizeof(unsigned char)*fc);
        }

        if (fc < 256)
            i->addrs.count = (unsigned char) fc;
        else
            i->addrs.count = 255;

        if (ttl == 0 || ttl > Config.positiveDnsTtl)
            ttl = Config.positiveDnsTtl;

        if (ttl < Config.negativeDnsTtl)
            ttl = Config.negativeDnsTtl;

        i->expires = squid_curtime + ttl;

        i->flags.negcached = 0;

        i->addrs.cur = 0;

        i->addrs.badcount = 0;
    }

    if(fc == 0) {
        i->error_message = xstrdup("No DNS Records");
    }

    /* finish the lookup we were doing on parent when we got side-tracked for CNAME loop */
    if(i->cname_wait == 0) {
        ipcacheAddEntry(i);
        ipcacheCallback(i);
    }
    // else still more CNAME to be found.
}

void
