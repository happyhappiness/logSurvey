        case 'm':
            if (optarg) {
#if MALLOC_DBG
                malloc_debug_level = atoi(optarg);
#else

                fatal("Need to add -DMALLOC_DBG when compiling to use -mX option");
#endif

            } else {
