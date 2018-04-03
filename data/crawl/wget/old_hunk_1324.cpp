Remote file exists.\n\n"));
                        }
                      ret = RETROK; /* RETRUNNEEDED is not for caller. */
                      goto exit;
                    }
                }
tests/ChangeLog                  |  3 ++-
tests/Test-proxied-https-auth.px | 10 ++++++++++
2 files changed, 12 insertions(+), 1 deletion(-)
