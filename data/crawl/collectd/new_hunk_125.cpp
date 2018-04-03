  return 0;
}

DEF_TEST (get_rate) {
  /* We re-declare the struct here so we can inspect its content. */
  struct {
    cdtime_t start_time;
    cdtime_t sum;
    size_t num;
    cdtime_t min;
    cdtime_t max;
    cdtime_t bin_width;
    int histogram[HISTOGRAM_NUM_BINS];
  } *peek;
  latency_counter_t *l;

  CHECK_NOT_NULL (l = latency_counter_create ());
  peek = (void *) l;

  for (time_t i = 1; i <= 125; i++) {
    latency_counter_add (l, TIME_T_TO_CDTIME_T(i));
  }

  /* We expect a bucket width of 125ms. */
  EXPECT_EQ_UINT64 (DOUBLE_TO_CDTIME_T(0.125), peek->bin_width);

  struct {
    size_t index;
    int want;
  } bucket_cases[] = {
    { 0, 0}, /* (0.000-0.125] */
    { 1, 0}, /* (0.125-0.250] */
    { 2, 0}, /* (0.250-0.375] */
    { 3, 0}, /* (0.375-0.500] */
    { 4, 0}, /* (0.500-0.625] */
    { 5, 0}, /* (0.625-0.750] */
    { 6, 0}, /* (0.750-0.875] */
    { 7, 1}, /* (0.875-1.000] */
    { 8, 0}, /* (1.000-1.125] */
    { 9, 0}, /* (1.125-1.250] */
    {10, 0}, /* (1.250-1.375] */
    {11, 0}, /* (1.375-1.500] */
    {12, 0}, /* (1.500-1.625] */
    {13, 0}, /* (1.625-1.750] */
    {14, 0}, /* (1.750-1.875] */
    {15, 1}, /* (1.875-2.000] */
    {16, 0}, /* (2.000-2.125] */
  };

  for (size_t i = 0; i < STATIC_ARRAY_SIZE(bucket_cases); i++) {
    size_t index = bucket_cases[i].index;
    EXPECT_EQ_INT(bucket_cases[i].want, peek->histogram[index]);
  }

  struct {
    cdtime_t lower_bound;
    cdtime_t upper_bound;
    double want;
  } cases[] = {
    { // bucket 6 is zero
      DOUBLE_TO_CDTIME_T(0.750),
      DOUBLE_TO_CDTIME_T(0.875),
      0.00,
    },
    { // bucket 7 contains the t=1 update
      DOUBLE_TO_CDTIME_T(0.875),
      DOUBLE_TO_CDTIME_T(1.000),
      1.00,
    },
    { // range: bucket 7 - bucket 15; contains the t=1 and t=2 updates
      DOUBLE_TO_CDTIME_T(0.875),
      DOUBLE_TO_CDTIME_T(2.000),
      2.00,
    },
    { // lower bucket is only partially applied
      DOUBLE_TO_CDTIME_T(0.875 + (0.125 / 4)),
      DOUBLE_TO_CDTIME_T(2.000),
      1.75,
    },
    { // upper bucket is only partially applied
      DOUBLE_TO_CDTIME_T(0.875),
      DOUBLE_TO_CDTIME_T(2.000 - (0.125 / 4)),
      1.75,
    },
    { // both buckets are only partially applied
      DOUBLE_TO_CDTIME_T(0.875 + (0.125 / 4)),
      DOUBLE_TO_CDTIME_T(2.000 - (0.125 / 4)),
      1.50,
    },
    { // lower bound is unspecified
      0,
      DOUBLE_TO_CDTIME_T(2.000),
      2.00,
    },
    { // upper bound is unspecified
      DOUBLE_TO_CDTIME_T(125.000 - 0.125),
      0,
      1.00,
    },
    { // overflow test
      DOUBLE_TO_CDTIME_T(1.000),
      DOUBLE_TO_CDTIME_T(999999),
      124.00,
    },
  };

  for (size_t i = 0; i < STATIC_ARRAY_SIZE(cases); i++) {
    cdtime_t now = peek->start_time + TIME_T_TO_CDTIME_T(1);
    EXPECT_EQ_DOUBLE (cases[i].want,
                      latency_counter_get_rate (l, cases[i].lower_bound, cases[i].upper_bound, now));
  }

  latency_counter_destroy (l);
  return 0;
