      AC_CHECK_LIB(dl, shl_load)
    ])

    AC_CHECK_LIB(z, compress)
    AC_CHECK_LIB(crypto, EVP_MD_CTX_init)
    AC_CHECK_LIB(ssl, ERR_func_error_string,,
                AC_MSG_ERROR([openssl development libraries not found]))
   AC_LIBOBJ([openssl])
], [
  # --with-ssl is not gnutls: check if it's no
  AS_IF([test x"$with_ssl" != xno], [
