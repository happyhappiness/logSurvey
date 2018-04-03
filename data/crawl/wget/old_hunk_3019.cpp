  if (!resp->headers)
    return;
  for (i = 0; resp->headers[i + 1]; i++)
    print_server_response_1 (prefix, resp->headers[i], resp->headers[i + 1]);
}

/* Parse the `Content-Range' header and extract the information it
