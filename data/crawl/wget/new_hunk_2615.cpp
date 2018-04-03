        --e;
      if (b < e && e[-1] == '\r')
        --e;
      print_response_line(prefix, b, e);
    }
}

