  return 0;
}

int lcc_network_parse(void *data, size_t data_size, lcc_value_list_writer_t w) {
  buffer_t *b = &(buffer_t){
      .data = data, .len = data_size,
  };
