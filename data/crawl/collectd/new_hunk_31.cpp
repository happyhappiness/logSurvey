      cmd_handle_flush(fhout, buffer);
    } else {
      if (fprintf(fhout, "-1 Unknown command: %s\n", fields[0]) < 0) {
        WARNING("unixsock plugin: failed to write to socket #%i: %s",
                fileno(fhout), STRERRNO);
        break;
      }
    }
