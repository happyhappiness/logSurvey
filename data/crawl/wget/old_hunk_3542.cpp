  SSL_connect (*con);  
  if ((*con)->state != SSL_ST_OK)
    return 1;
  return 0;
}

