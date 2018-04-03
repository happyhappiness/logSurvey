    }

#endif

    // prevent infinite fetch loops in the request parser
    // due to buffer full but not enough data recived to finish parse
    if (Config.maxRequestBufferSize <= Config.maxRequestHeaderSize) {
        fatalf("Client request buffer of %d bytes cannot hold a request with %d bytes of headers." \
               " Change client_request_buffer_max or request_header_max_size limits.",
               Config.maxRequestBufferSize, Config.maxRequestHeaderSize);
    }
}

/** Parse a line containing an obsolete directive.