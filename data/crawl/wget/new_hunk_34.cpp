  else
    src = host;

#if IDN2_VERSION_NUMBER >= 0x00140000
  /* IDN2_TRANSITIONAL implies input NFC encoding */
  if ((ret = idn2_lookup_u8 (src, (uint8_t **) &ascii_encoded, IDN2_TRANSITIONAL)) != IDN2_OK)
