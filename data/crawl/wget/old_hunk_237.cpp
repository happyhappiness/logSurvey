          wgint bytes_sofar = bytes_displayed - dp->initial_length;
          double eta = dltime * bytes_remaining / bytes_sofar;
          if (eta < INT_MAX - 1)
            logprintf (LOG_VERBOSE, " %s",
                       eta_to_human_short ((int) (eta + 0.5), true));
        }
    }
