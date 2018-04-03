                  continue;
                }

              for (mchksum_ptr = mfile->checksums; *mchksum_ptr; mchksum_ptr++)
                {
                  char md2[MD2_DIGEST_SIZE];
