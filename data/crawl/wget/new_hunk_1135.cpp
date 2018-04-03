
  if (status & GNUTLS_CERT_INVALID)
    {
      logprintf (LOG_NOTQUIET, _("%s: The certificate of %s is not trusted.\n"),
                 severity, quote (escnonprint (host)));
      success = false;
    }
  if (status & GNUTLS_CERT_SIGNER_NOT_FOUND)
    {
      logprintf (LOG_NOTQUIET, _("%s: The certificate of %s hasn't got a known issuer.\n"),
                 severity, quote (escnonprint (host)));
      success = false;
    }
  if (status & GNUTLS_CERT_REVOKED)
    {
      logprintf (LOG_NOTQUIET, _("%s: The certificate of %s has been revoked.\n"),
                 severity, quote (escnonprint (host)));
      success = false;
    }

src/ChangeLog |  1 +
src/init.c    | 54 +++++++++++++++++++++++++++---------------------------
2 files changed, 28 insertions(+), 27 deletions(-)
