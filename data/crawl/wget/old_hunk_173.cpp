              request_free (req);
              return VERIFCERTERR;
            }
          using_ssl = true;
        }
#endif /* HAVE_SSL */
    }

  /* Open the temporary file where we will write the request. */
  if (warc_enabled)
