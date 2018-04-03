
        case 'm':
            if (optarg) {
#if MALLOC_DBG
                malloc_debug_level = atoi(optarg);
                /* NOTREACHED */
                break;
#else

                fatal("Need to add -DMALLOC_DBG when compiling to use -mX option");
                /* NOTREACHED */
#endif

            } else {
#if XMALLOC_TRACE
                xmalloc_trace = !xmalloc_trace;
