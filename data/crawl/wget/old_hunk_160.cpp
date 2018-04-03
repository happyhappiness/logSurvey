        }
    }

  if (statcode == HTTP_STATUS_RANGE_NOT_SATISFIABLE
      || (!opt.timestamping && hs->restval > 0 && statcode == HTTP_STATUS_OK
          && contrange == 0 && contlen >= 0 && hs->restval >= contlen))
