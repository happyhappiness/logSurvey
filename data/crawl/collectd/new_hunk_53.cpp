  }

  if (vl.values_len != 3) {
    fprintf(stderr, "parse_values(): vl.values_len = %" PRIsz ", want 3\n",
            vl.values_len);
    return -1;
  }

  int want_types[] = {LCC_TYPE_GAUGE, LCC_TYPE_DERIVE, LCC_TYPE_GAUGE};
  for (size_t i = 0; i < sizeof(want_types) / sizeof(want_types[0]); i++) {
    if (vl.values_types[i] != want_types[i]) {
      fprintf(stderr,
              "parse_values(): vl.values_types[%" PRIsz "] = %d, want %d\n", i,
              vl.values_types[i], want_types[i]);
      ret = -1;
    }
