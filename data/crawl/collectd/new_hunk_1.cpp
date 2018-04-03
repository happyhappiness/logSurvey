    uint8_t buffer[LCC_NETWORK_BUFFER_SIZE_DEFAULT];
    size_t buffer_size = sizeof(buffer);
    if (decode_string(raw_packet_data[i], buffer, &buffer_size)) {
      fprintf(stderr, "lcc_network_parse(raw_packet_data[%" PRIsz "]):"
                      " decoding string failed\n",
              i);
      return -1;
    }

