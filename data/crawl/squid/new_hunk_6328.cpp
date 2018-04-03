#if MEM_GEN_TRACE
    log_trace_done();
#endif
    debug(1, 0) ("Squid Cache (Version %s): Exiting normally.\n",
	version_string);
    fclose(debug_log);
    exit(0);
}
