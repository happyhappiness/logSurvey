      return NULL;
    }

  /* we need a conversion to lowercase */
  lower = u8_tolower ((uint8_t *) src, u8_strlen ((uint8_t *) src) + 1, 0, UNINORM_NFKC, NULL, &len);
  if (!lower)
