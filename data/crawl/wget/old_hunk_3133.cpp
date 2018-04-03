  if (b < e && e[-1] == '\r')
    --e;
  BOUNDED_TO_ALLOCA (b, e, ln);
  logprintf (LOG_VERBOSE, "  %s\n", ln);
}

static void
print_server_response (const struct response *resp)
{
  int i;
  if (!resp->headers)
    return;
  for (i = 0; resp->headers[i + 1]; i++)
    print_server_response_1 (resp->headers[i], resp->headers[i + 1]);
}

/* Parse the `Content-Range' header and extract the information it
