        --e;
      /* This is safe even on printfs with broken handling of "%.<n>s"
         because resp->headers ends with \0.  */
      logprintf (LOG_VERBOSE, "%s%.*s\n", prefix, e - b, b);
    }
}

