      return NULL;
    }

#if IDN2_VERSION_NUMBER >= 0x00140000
  /* IDN2_TRANSITIONAL implies input NFC encoding */
  if ((ret = idn2_lookup_u8 (src, (uint8_t **) &ascii_encoded, IDN2_TRANSITIONAL)) != IDN2_OK)
    {
      logprintf (LOG_VERBOSE, _("idn_encode failed (%d): %s\n"), ret,
                 quote (idn2_strerror (ret)));
    }
#else
  /* we need a conversion to lowercase */
  lower = u8_tolower ((uint8_t *) src, u8_strlen ((uint8_t *) src) + 1, 0, UNINORM_NFKC, NULL, &len);
  if (!lower)
