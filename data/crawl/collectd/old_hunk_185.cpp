  CHECK_NOT_NULL (l = latency_counter_create ());

  for (i = 0; i < STATIC_ARRAY_SIZE (cases); i++) {
    latency_counter_add (l, DOUBLE_TO_CDTIME_T (cases[i].val));

    DBLEQ (cases[i].min, CDTIME_T_TO_DOUBLE (latency_counter_get_min (l)));