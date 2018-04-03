        strcat(msg, "\r\n");
    }

    debugVerbose(1, "Request:" << std::endl << msg << std::endl << ".");

    if (ping) {
#if HAVE_SIGACTION
