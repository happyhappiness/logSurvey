        {
          logprintf (LOG_NOTQUIET,
                     _("Cookie coming from %s attempted to set domain to %s\n"),
                     escnonprint (host), escnonprint (cookie->domain));
          xfree (cookie->domain);
          goto copy_domain;
        }
src/ftp-basic.c | 8 +++++---
1 file changed, 5 insertions(+), 3 deletions(-)
