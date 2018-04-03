
        case 'm':
            if (optarg) {
                if (*optarg == 'c') {
                    MemPools::GetInstance().setDefaultPoolChunking(0);
                } else {
#if MALLOC_DBG
                    malloc_debug_level = atoi(optarg);
#else

                    fatal("Need to add -DMALLOC_DBG when compiling to use -mX option");
#endif

                }

            } else {
#if XMALLOC_TRACE
                xmalloc_trace = !xmalloc_trace;
