static int kafka_write(const data_set_t *, const value_list_t *, user_data_t *);
static int32_t kafka_partition(const rd_kafka_topic_t *, const void *, size_t,
                               int32_t, void *, void *);

static int32_t kafka_partition(const rd_kafka_topic_t *rkt,
                               const void *keydata, size_t keylen,
