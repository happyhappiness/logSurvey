              default:
                /* Can't happen. */
                assert (1);
            }

          if (!opt.server_response)
            logprintf (LOG_VERBOSE, "==> CWD (%d) %s ... ", cwd_count,
