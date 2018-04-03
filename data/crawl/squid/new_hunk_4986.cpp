    char *cenc = mimeGetContentEncoding(name);

    if (cenc)
        mb->Printf("Content-Encoding: %s\r\n", cenc);

    mb->Printf("Content-Type: %s\r\n",
               ctype ? ctype : def_ctype);
}


