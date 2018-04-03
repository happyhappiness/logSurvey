            /** \par n
             * Set global option opt_signal_service (to true).
             * Stores the additional parameter given in global service_name */
            // XXX: verify that the new name has ONLY alphanumeric characters
            xfree(service_name);
            service_name = xstrdup(optarg);
            opt_signal_service = true;
            break;

#if USE_WIN32_SERVICE
