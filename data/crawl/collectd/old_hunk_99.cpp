
  return ret;
}

typedef struct {
  uint8_t *data;
  size_t len;
} buffer_t;

static int buffer_next(buffer_t *b, void *out, size_t n) {
  if (b->len < n) {
    return -1;
  }
  memmove(out, b->data, n);

  b->data += n;
  b->len -= n;

  return 0;
}

static int buffer_uint16(buffer_t *b, uint16_t *out) {
  uint16_t tmp;
  if (buffer_next(b, &tmp, sizeof(tmp)) != 0)
    return -1;

  *out = be16toh(tmp);
  return 0;
}

#define TYPE_HOST 0x0000
#define TYPE_TIME 0x0001
#define TYPE_TIME_HR 0x0008
#define TYPE_PLUGIN 0x0002
#define TYPE_PLUGIN_INSTANCE 0x0003
#define TYPE_TYPE 0x0004
#define TYPE_TYPE_INSTANCE 0x0005
#define TYPE_VALUES 0x0006
#define TYPE_INTERVAL 0x0007
#define TYPE_INTERVAL_HR 0x0009
#define TYPE_SIGN_SHA256 0x0200
#define TYPE_ENCR_AES256 0x0210

static int parse_int(void *payload, size_t payload_size, uint64_t *out) {
  uint64_t tmp;

  if (payload_size != sizeof(tmp))
    return EINVAL;

  memmove(&tmp, payload, sizeof(tmp));
  *out = be64toh(tmp);
  return 0;
}

static int parse_string(void *payload, size_t payload_size, char *out,
                        size_t out_size) {
  char *in = payload;

  if ((payload_size < 1) || (in[payload_size - 1] != 0) ||
      (payload_size > out_size))
    return EINVAL;

  strncpy(out, in, out_size);
  return 0;
}

static int parse_identifier(uint16_t type, void *payload, size_t payload_size,
                            lcc_value_list_t *state) {
  char buf[LCC_NAME_LEN];

  if (parse_string(payload, payload_size, buf, sizeof(buf)) != 0)
    return EINVAL;

  switch (type) {
  case TYPE_HOST:
    memmove(state->identifier.host, buf, LCC_NAME_LEN);
    break;
  case TYPE_PLUGIN:
    memmove(state->identifier.plugin, buf, LCC_NAME_LEN);
    break;
  case TYPE_PLUGIN_INSTANCE:
    memmove(state->identifier.plugin_instance, buf, LCC_NAME_LEN);
    break;
  case TYPE_TYPE:
    memmove(state->identifier.type, buf, LCC_NAME_LEN);
    break;
  case TYPE_TYPE_INSTANCE:
    memmove(state->identifier.type_instance, buf, LCC_NAME_LEN);
    break;
  default:
    return EINVAL;
  }

  return 0;
}

static int parse_time(uint16_t type, void *payload, size_t payload_size,
                      lcc_value_list_t *state) {
  uint64_t tmp = 0;
  if (parse_int(payload, payload_size, &tmp))
    return EINVAL;

  double t = (double)tmp;
  switch (type) {
  case TYPE_INTERVAL:
    state->interval = t;
    break;
  case TYPE_INTERVAL_HR:
    state->interval = t / 1073741824.0;
    break;
  case TYPE_TIME:
    state->time = t;
    break;
  case TYPE_TIME_HR:
    state->time = t / 1073741824.0;
    break;
  default:
    return EINVAL;
  }

  return 0;
}

static double ntohd(double val) /* {{{ */
{
  static int config = 0;

  union {
    uint8_t byte[8];
    double floating;
  } in = {
      .floating = val,
  };
  union {
    uint8_t byte[8];
    double floating;
  } out = {
      .byte = {0},
  };

  if (config == 0) {
    double d = 8.642135e130;
    uint8_t b[8];

    memcpy(b, &d, sizeof(b));

    if ((b[0] == 0x2f) && (b[1] == 0x25) && (b[2] == 0xc0) && (b[3] == 0xc7) &&
        (b[4] == 0x43) && (b[5] == 0x2b) && (b[6] == 0x1f) && (b[7] == 0x5b))
      config = 1; /* need nothing */
    else if ((b[7] == 0x2f) && (b[6] == 0x25) && (b[5] == 0xc0) &&
             (b[4] == 0xc7) && (b[3] == 0x43) && (b[2] == 0x2b) &&
             (b[1] == 0x1f) && (b[0] == 0x5b))
      config = 2; /* endian flip */
    else if ((b[4] == 0x2f) && (b[5] == 0x25) && (b[6] == 0xc0) &&
             (b[7] == 0xc7) && (b[0] == 0x43) && (b[1] == 0x2b) &&
             (b[2] == 0x1f) && (b[3] == 0x5b))
      config = 3; /* int swap */
    else
      config = 4;
  }

  if (memcmp((char[]){0, 0, 0, 0, 0, 0, 0xf8, 0x7f}, in.byte, 8) == 0) {
    return NAN;
  } else if (config == 1) {
    return val;
  } else if (config == 2) {
    in.floating = val;
    out.byte[0] = in.byte[7];
    out.byte[1] = in.byte[6];
    out.byte[2] = in.byte[5];
    out.byte[3] = in.byte[4];
    out.byte[4] = in.byte[3];
    out.byte[5] = in.byte[2];
    out.byte[6] = in.byte[1];
    out.byte[7] = in.byte[0];
    return (out.floating);
  } else if (config == 3) {
    in.floating = val;
    out.byte[0] = in.byte[4];
    out.byte[1] = in.byte[5];
    out.byte[2] = in.byte[6];
    out.byte[3] = in.byte[7];
    out.byte[4] = in.byte[0];
    out.byte[5] = in.byte[1];
    out.byte[6] = in.byte[2];
    out.byte[7] = in.byte[3];
    return out.floating;
  } else {
    /* If in doubt, just copy the value back to the caller. */
    return val;
  }
} /* }}} double ntohd */

static int parse_values(void *payload, size_t payload_size,
                        lcc_value_list_t *state) {
  buffer_t *b = &(buffer_t){
      .data = payload, .len = payload_size,
  };

  uint16_t n;
  if (buffer_uint16(b, &n))
    return EINVAL;

  if (((size_t)n * 9) != b->len)
    return EINVAL;

  state->values_len = (size_t)n;
  state->values = calloc(sizeof(*state->values), state->values_len);
  state->values_types = calloc(sizeof(*state->values_types), state->values_len);
  if ((state->values == NULL) || (state->values_types == NULL)) {
    free(state->values);
    free(state->values_types);
    return ENOMEM;
  }

  for (uint16_t i = 0; i < n; i++) {
    uint8_t tmp;
    if (buffer_next(b, &tmp, sizeof(tmp)))
      return EINVAL;
    state->values_types[i] = (int)tmp;
  }

  for (uint16_t i = 0; i < n; i++) {
    uint64_t tmp;
    if (buffer_next(b, &tmp, sizeof(tmp)))
      return EINVAL;

    if (state->values_types[i] == LCC_TYPE_GAUGE) {
      union {
        uint64_t i;
        double d;
      } conv = {.i = tmp};
      state->values[i].gauge = ntohd(conv.d);
      continue;
    }

    tmp = be64toh(tmp);
    switch (state->values_types[i]) {
    case LCC_TYPE_COUNTER:
      state->values[i].counter = (counter_t)tmp;
      break;
    case LCC_TYPE_DERIVE:
      state->values[i].derive = (derive_t)tmp;
      break;
    case LCC_TYPE_ABSOLUTE:
      state->values[i].absolute = (absolute_t)tmp;
      break;
    default:
      return EINVAL;
    }
  }

  return 0;
}

static int verify_sha256(void *payload, size_t payload_size,
                         char const *username, char const *password,
                         uint8_t hash_provided[32]) {
  gcry_md_hd_t hd = NULL;

  gcry_error_t err = gcry_md_open(&hd, GCRY_MD_SHA256, GCRY_MD_FLAG_HMAC);
  if (err != 0) {
    /* TODO(octo): use gcry_strerror(err) to create an error string. */
    return -1;
  }

  err = gcry_md_setkey(hd, password, strlen(password));
  if (err != 0) {
    gcry_md_close(hd);
    return -1;
  }

  gcry_md_write(hd, username, strlen(username));
  gcry_md_write(hd, payload, payload_size);

  unsigned char *hash_calculated = gcry_md_read(hd, GCRY_MD_SHA256);
  if (!hash_calculated) {
    gcry_md_close(hd);
    return -1;
  }

  int ret = memcmp(hash_provided, hash_calculated, 32);

  gcry_md_close(hd);
  hash_calculated = NULL;

  return !!ret;
}

static int parse_sign_sha256(void *signature, size_t signature_len,
                             void *payload, size_t payload_size,
                             lcc_network_parse_options_t const *opts) {
  if (opts->password_lookup == NULL) {
    /* TODO(octo): print warning */
    return network_parse(payload, payload_size, NONE, opts);
  }

  buffer_t *b = &(buffer_t){
      .data = signature, .len = signature_len,
  };

  uint8_t hash[32];
  if (buffer_next(b, hash, sizeof(hash)))
    return EINVAL;

  char username[b->len + 1];
  memset(username, 0, sizeof(username));
  if (buffer_next(b, username, sizeof(username) - 1)) {
    return EINVAL;
  }

  char const *password = opts->password_lookup(username);
  if (!password)
    return network_parse(payload, payload_size, NONE, opts);

  int status = verify_sha256(payload, payload_size, username, password, hash);
  if (status != 0)
    return status;

  return network_parse(payload, payload_size, SIGN, opts);
}

static int decrypt_aes256(buffer_t *b, void *iv, size_t iv_size,
                          char const *password) {
  gcry_cipher_hd_t cipher = NULL;

  if (gcry_cipher_open(&cipher, GCRY_CIPHER_AES256, GCRY_CIPHER_MODE_OFB,
                       /* flags = */ 0))
    return -1;

  uint8_t pwhash[32] = {0};
  gcry_md_hash_buffer(GCRY_MD_SHA256, pwhash, password, strlen(password));

  fprintf(stderr, "sizeof(iv) = %zu\n", sizeof(iv));
  if (gcry_cipher_setkey(cipher, pwhash, sizeof(pwhash)) ||
      gcry_cipher_setiv(cipher, iv, iv_size) ||
      gcry_cipher_decrypt(cipher, b->data, b->len, /* in = */ NULL,
                          /* in_size = */ 0)) {
    gcry_cipher_close(cipher);
    return -1;
  }

  gcry_cipher_close(cipher);
  return 0;
}

static int parse_encrypt_aes256(void *data, size_t data_size,
                                lcc_network_parse_options_t const *opts) {
  if (opts->password_lookup == NULL) {
    /* TODO(octo): print warning */
    return ENOENT;
  }

  buffer_t *b = &(buffer_t){
      .data = data, .len = data_size,
  };

  uint16_t username_len;
  if (buffer_uint16(b, &username_len))
    return EINVAL;
  if ((size_t)username_len > data_size)
    return ENOMEM;
  char username[((size_t)username_len) + 1];
  memset(username, 0, sizeof(username));
  if (buffer_next(b, username, sizeof(username)))
    return EINVAL;

  char const *password = opts->password_lookup(username);
  if (!password)
    return ENOENT;

  uint8_t iv[16];
  if (buffer_next(b, iv, sizeof(iv)))
    return EINVAL;

  int status = decrypt_aes256(b, iv, sizeof(iv), password);
  if (status != 0)
    return status;

  uint8_t hash_provided[20];
  if (buffer_next(b, hash_provided, sizeof(hash_provided))) {
    return -1;
  }

  uint8_t hash_calculated[20];
  gcry_md_hash_buffer(GCRY_MD_SHA1, hash_calculated, b->data, b->len);

  if (memcmp(hash_provided, hash_calculated, sizeof(hash_provided)) != 0) {
    return -1;
  }

  return network_parse(b->data, b->len, ENCRYPT, opts);
}

static int network_parse(void *data, size_t data_size, lcc_security_level_t sl,
                         lcc_network_parse_options_t const *opts) {
  buffer_t *b = &(buffer_t){
      .data = data, .len = data_size,
  };

  lcc_value_list_t state = {0};

  while (b->len > 0) {
    uint16_t type = 0, sz = 0;
    if (buffer_uint16(b, &type) || buffer_uint16(b, &sz)) {
      DEBUG("lcc_network_parse(): reading type and/or length failed.\n");
      return EINVAL;
    }

    if ((sz < 5) || (((size_t)sz - 4) > b->len)) {
      DEBUG("lcc_network_parse(): invalid 'sz' field: sz = %" PRIu16
            ", b->len = %zu\n",
            sz, b->len);
      return EINVAL;
    }
    sz -= 4;

    uint8_t payload[sz];
    if (buffer_next(b, payload, sizeof(payload)))
      return EINVAL;

    switch (type) {
    case TYPE_HOST:
    case TYPE_PLUGIN:
    case TYPE_PLUGIN_INSTANCE:
    case TYPE_TYPE:
    case TYPE_TYPE_INSTANCE: {
      if (parse_identifier(type, payload, sizeof(payload), &state)) {
        DEBUG("lcc_network_parse(): parse_identifier failed.\n");
        return EINVAL;
      }
      break;
    }

    case TYPE_INTERVAL:
    case TYPE_INTERVAL_HR:
    case TYPE_TIME:
    case TYPE_TIME_HR: {
      if (parse_time(type, payload, sizeof(payload), &state)) {
        DEBUG("lcc_network_parse(): parse_time failed.\n");
        return EINVAL;
      }
      break;
    }

    case TYPE_VALUES: {
      lcc_value_list_t vl = state;
      if (parse_values(payload, sizeof(payload), &vl)) {
        DEBUG("lcc_network_parse(): parse_values failed.\n");
        return EINVAL;
      }

      /* TODO(octo): skip if current_security_level < required_security_level */

      int status = opts->writer(&vl);

      free(vl.values);
      free(vl.values_types);

      if (status != 0)
        return status;
      break;
    }

    case TYPE_SIGN_SHA256: {
      int status =
          parse_sign_sha256(payload, sizeof(payload), b->data, b->len, opts);
      if (status != 0) {
        DEBUG("lcc_network_parse(): parse_sign_sha256() = %d\n", status);
        return -1;
      }
      /* parse_sign_sha256, if successful, consumes all remaining data. */
      b->data = NULL;
      b->len = 0;
      break;
    }

    case TYPE_ENCR_AES256: {
      int status = parse_encrypt_aes256(payload, sizeof(payload), opts);
      if (status != 0) {
        DEBUG("lcc_network_parse(): parse_encrypt_aes256() = %d\n", status);
        return -1;
      }
      break;
    }

    default: {
      DEBUG("lcc_network_parse(): ignoring unknown type %" PRIu16 "\n", type);
      return EINVAL;
    }
    }
  }

  return 0;
}

int lcc_network_parse(void *data, size_t data_size,
                      lcc_network_parse_options_t opts) {
  if (opts.password_lookup) {
    int status;
    if ((status = init_gcrypt())) {
      return status;
    }
  }

  return network_parse(data, data_size, NONE, &opts);
}