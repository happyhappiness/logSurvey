    f->page_faults = rusage_pagefaults(&rusage);
    f->cputime = rusage_cputime(&rusage);

    stats.sample_time = f->timestamp;
    stats.client_http_requests = f->client_http.requests;
    stats.client_http_hits = f->client_http.hits;
    stats.client_http_errors = f->client_http.errors;
    stats.client_http_kbytes_in = f->client_http.kbytes_in.kb;
    stats.client_http_kbytes_out = f->client_http.kbytes_out.kb;
    stats.client_http_hit_kbytes_out = f->client_http.hit_kbytes_out.kb;

    stats.server_all_requests = f->server.all.requests;
    stats.server_all_errors = f->server.all.errors;
    stats.server_all_kbytes_in = f->server.all.kbytes_in.kb;
    stats.server_all_kbytes_out = f->server.all.kbytes_out.kb;

    stats.server_http_requests = f->server.http.requests;
    stats.server_http_errors = f->server.http.errors;
    stats.server_http_kbytes_in = f->server.http.kbytes_in.kb;
    stats.server_http_kbytes_out = f->server.http.kbytes_out.kb;

    stats.server_ftp_requests = f->server.ftp.requests;
    stats.server_ftp_errors = f->server.ftp.errors;
    stats.server_ftp_kbytes_in = f->server.ftp.kbytes_in.kb;
    stats.server_ftp_kbytes_out = f->server.ftp.kbytes_out.kb;

    stats.server_other_requests = f->server.other.requests;
    stats.server_other_errors = f->server.other.errors;
    stats.server_other_kbytes_in = f->server.other.kbytes_in.kb;
    stats.server_other_kbytes_out = f->server.other.kbytes_out.kb;

    stats.icp_pkts_sent = f->icp.pkts_sent;
    stats.icp_pkts_recv = f->icp.pkts_recv;
    stats.icp_queries_sent = f->icp.queries_sent;
    stats.icp_replies_sent = f->icp.replies_sent;
    stats.icp_queries_recv = f->icp.queries_recv;
    stats.icp_replies_recv = f->icp.replies_recv;
    stats.icp_query_timeouts = f->icp.query_timeouts;
    stats.icp_replies_queued = f->icp.replies_queued;
    stats.icp_kbytes_sent = f->icp.kbytes_sent.kb;
    stats.icp_kbytes_recv = f->icp.kbytes_recv.kb;
    stats.icp_q_kbytes_sent = f->icp.q_kbytes_sent.kb;
    stats.icp_r_kbytes_sent = f->icp.r_kbytes_sent.kb;
    stats.icp_q_kbytes_recv = f->icp.q_kbytes_recv.kb;
    stats.icp_r_kbytes_recv = f->icp.r_kbytes_recv.kb;

#if USE_CACHE_DIGESTS

    stats.icp_times_used = f->icp.times_used;
    stats.cd_times_used = f->cd.times_used;
    stats.cd_msgs_sent = f->cd.msgs_sent;
    stats.cd_msgs_recv = f->cd.msgs_recv;
    stats.cd_memory = f->cd.memory.kb;
    stats.cd_local_memory = store_digest ? store_digest->mask_size / 1024 : 0;
    stats.cd_kbytes_sent = f->cd.kbytes_sent.kb;
    stats.cd_kbytes_recv = f->cd.kbytes_recv.kb;
#endif

    stats.unlink_requests = f->unlink.requests;
    stats.page_faults = f->page_faults;
    stats.select_loops = f->select_loops;
    stats.cpu_time = f->cputime;
    stats.wall_time = tvSubDsec(f->timestamp, current_time);
    stats.swap_outs = f->swap.outs;
    stats.swap_ins = f->swap.ins;
    stats.swap_files_cleaned = f->swap.files_cleaned;
    stats.aborted_requests = f->aborted_requests;
}

void
DumpCountersStats(Mgr::CountersActionData& stats, StoreEntry* sentry)
{
    storeAppendPrintf(sentry, "sample_time = %d.%d (%s)\n",
                      (int) stats.sample_time.tv_sec,
                      (int) stats.sample_time.tv_usec,
                      mkrfc1123(stats.sample_time.tv_sec));
    storeAppendPrintf(sentry, "client_http.requests = %.0f\n",
                      stats.client_http_requests);
    storeAppendPrintf(sentry, "client_http.hits = %.0f\n",
                      stats.client_http_hits);
    storeAppendPrintf(sentry, "client_http.errors = %.0f\n",
                      stats.client_http_errors);
    storeAppendPrintf(sentry, "client_http.kbytes_in = %.0f\n",
                      stats.client_http_kbytes_in);
    storeAppendPrintf(sentry, "client_http.kbytes_out = %.0f\n",
                      stats.client_http_kbytes_out);
    storeAppendPrintf(sentry, "client_http.hit_kbytes_out = %.0f\n",
                      stats.client_http_hit_kbytes_out);

    storeAppendPrintf(sentry, "server.all.requests = %.0f\n",
                      stats.server_all_requests);
    storeAppendPrintf(sentry, "server.all.errors = %.0f\n",
                      stats.server_all_errors);
    storeAppendPrintf(sentry, "server.all.kbytes_in = %.0f\n",
                      stats.server_all_kbytes_in);
    storeAppendPrintf(sentry, "server.all.kbytes_out = %.0f\n",
                      stats.server_all_kbytes_out);

    storeAppendPrintf(sentry, "server.http.requests = %.0f\n",
                      stats.server_http_requests);
    storeAppendPrintf(sentry, "server.http.errors = %.0f\n",
                      stats.server_http_errors);
    storeAppendPrintf(sentry, "server.http.kbytes_in = %.0f\n",
                      stats.server_http_kbytes_in);
    storeAppendPrintf(sentry, "server.http.kbytes_out = %.0f\n",
                      stats.server_http_kbytes_out);

    storeAppendPrintf(sentry, "server.ftp.requests = %.0f\n",
                      stats.server_ftp_requests);
    storeAppendPrintf(sentry, "server.ftp.errors = %.0f\n",
                      stats.server_ftp_errors);
    storeAppendPrintf(sentry, "server.ftp.kbytes_in = %.0f\n",
                      stats.server_ftp_kbytes_in);
    storeAppendPrintf(sentry, "server.ftp.kbytes_out = %.0f\n",
                      stats.server_ftp_kbytes_out);

    storeAppendPrintf(sentry, "server.other.requests = %.0f\n",
                      stats.server_other_requests);
    storeAppendPrintf(sentry, "server.other.errors = %.0f\n",
                      stats.server_other_errors);
    storeAppendPrintf(sentry, "server.other.kbytes_in = %.0f\n",
                      stats.server_other_kbytes_in);
    storeAppendPrintf(sentry, "server.other.kbytes_out = %.0f\n",
                      stats.server_other_kbytes_out);

    storeAppendPrintf(sentry, "icp.pkts_sent = %.0f\n",
                      stats.icp_pkts_sent);
    storeAppendPrintf(sentry, "icp.pkts_recv = %.0f\n",
                      stats.icp_pkts_recv);
    storeAppendPrintf(sentry, "icp.queries_sent = %.0f\n",
                      stats.icp_queries_sent);
    storeAppendPrintf(sentry, "icp.replies_sent = %.0f\n",
                      stats.icp_replies_sent);
    storeAppendPrintf(sentry, "icp.queries_recv = %.0f\n",
                      stats.icp_queries_recv);
    storeAppendPrintf(sentry, "icp.replies_recv = %.0f\n",
                      stats.icp_replies_recv);
    storeAppendPrintf(sentry, "icp.query_timeouts = %.0f\n",
                      stats.icp_query_timeouts);
    storeAppendPrintf(sentry, "icp.replies_queued = %.0f\n",
                      stats.icp_replies_queued);
    storeAppendPrintf(sentry, "icp.kbytes_sent = %.0f\n",
                      stats.icp_kbytes_sent);
    storeAppendPrintf(sentry, "icp.kbytes_recv = %.0f\n",
                      stats.icp_kbytes_recv);
    storeAppendPrintf(sentry, "icp.q_kbytes_sent = %.0f\n",
                      stats.icp_q_kbytes_sent);
    storeAppendPrintf(sentry, "icp.r_kbytes_sent = %.0f\n",
                      stats.icp_r_kbytes_sent);
    storeAppendPrintf(sentry, "icp.q_kbytes_recv = %.0f\n",
                      stats.icp_q_kbytes_recv);
    storeAppendPrintf(sentry, "icp.r_kbytes_recv = %.0f\n",
                      stats.icp_r_kbytes_recv);

#if USE_CACHE_DIGESTS

    storeAppendPrintf(sentry, "icp.times_used = %.0f\n",
                      stats.icp_times_used);
    storeAppendPrintf(sentry, "cd.times_used = %.0f\n",
                      stats.cd_times_used);
    storeAppendPrintf(sentry, "cd.msgs_sent = %.0f\n",
                      stats.cd_msgs_sent);
    storeAppendPrintf(sentry, "cd.msgs_recv = %.0f\n",
                      stats.cd_msgs_recv);
    storeAppendPrintf(sentry, "cd.memory = %.0f\n",
                      stats.cd_memory);
    storeAppendPrintf(sentry, "cd.local_memory = %.0f\n",
                      stats.cd_local_memory);
    storeAppendPrintf(sentry, "cd.kbytes_sent = %.0f\n",
                      stats.cd_kbytes_sent);
    storeAppendPrintf(sentry, "cd.kbytes_recv = %.0f\n",
                      stats.cd_kbytes_recv);
#endif

    storeAppendPrintf(sentry, "unlink.requests = %.0f\n",
                      stats.unlink_requests);
    storeAppendPrintf(sentry, "page_faults = %.0f\n",
                      stats.page_faults);
    storeAppendPrintf(sentry, "select_loops = %.0f\n",
                      stats.select_loops);
    storeAppendPrintf(sentry, "cpu_time = %f\n",
                      stats.cpu_time);
    storeAppendPrintf(sentry, "wall_time = %f\n",
                      stats.wall_time);
    storeAppendPrintf(sentry, "swap.outs = %.0f\n",
                      stats.swap_outs);
    storeAppendPrintf(sentry, "swap.ins = %.0f\n",
                      stats.swap_ins);
    storeAppendPrintf(sentry, "swap.files_cleaned = %.0f\n",
                      stats.swap_files_cleaned);
    storeAppendPrintf(sentry, "aborted_requests = %.0f\n",
                      stats.aborted_requests);
}

void
