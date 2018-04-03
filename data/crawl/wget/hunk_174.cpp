 } while (0)
 #endif /* def __VMS [else] */
 
-/* Retrieve a document through HTTP protocol.  It recognizes status
-   code, and correctly handles redirections.  It closes the network
-   socket.  If it receives an error from the functions below it, it
-   will print it if there is enough information to do so (almost
-   always), returning the error to the caller (i.e. http_loop).
-
-   Various HTTP parameters are stored to hs.
-
-   If PROXY is non-NULL, the connection will be made to the proxy
-   server, and u->url will be requested.  */
-static uerr_t
-gethttp (struct url *u, struct http_stat *hs, int *dt, struct url *proxy,
-         struct iri *iri, int count)
+static struct request *
+initialize_request (struct url *u, struct http_stat *hs, int *dt, struct url *proxy,
+                    bool inhibit_keep_alive, bool *basic_auth_finished,
+                    wgint *body_data_size, char **user, char **passwd, uerr_t *ret)
 {
-  struct request *req;
-
-  char *type;
-  char *user, *passwd;
-  char *proxyauth;
-  int statcode;
-  int write_error;
-  wgint contlen, contrange;
-  struct url *conn;
-  FILE *fp;
-  int err;
-
-  int sock = -1;
-
-  /* Set to 1 when the authorization has already been sent and should
-     not be tried again. */
-  bool auth_finished = false;
-
-  /* Set to 1 when just globally-set Basic authorization has been sent;
-   * should prevent further Basic negotiations, but not other
-   * mechanisms. */
-  bool basic_auth_finished = false;
-
-  /* Whether NTLM authentication is used for this request. */
-  bool ntlm_seen = false;
-
-  /* Whether our connection to the remote host is through SSL.  */
-  bool using_ssl = false;
-
-  /* Whether a HEAD request will be issued (as opposed to GET or
-     POST). */
   bool head_only = !!(*dt & HEAD_ONLY);
-
-  char *head;
-  struct response *resp;
-  char hdrval[512];
-  char *message;
-
-  /* Declare WARC variables. */
-  bool warc_enabled = (opt.warc_filename != NULL);
-  FILE *warc_tmp = NULL;
-  char warc_timestamp_str [21];
-  char warc_request_uuid [48];
-  ip_address *warc_ip = NULL;
-  off_t warc_payload_offset = -1;
-
-  /* Whether this connection will be kept alive after the HTTP request
-     is done. */
-  bool keep_alive;
-
-  /* Is the server using the chunked transfer encoding?  */
-  bool chunked_transfer_encoding = false;
-
-  /* Whether keep-alive should be inhibited.  */
-  bool inhibit_keep_alive =
-    !opt.http_keep_alive || opt.ignore_length;
-
-  /* Headers sent when using POST. */
-  wgint body_data_size = 0;
-
-  bool host_lookup_failed = false;
-
-#ifdef HAVE_SSL
-  if (u->scheme == SCHEME_HTTPS)
-    {
-      /* Initialize the SSL context.  After this has once been done,
-         it becomes a no-op.  */
-      if (!ssl_init ())
-        {
-          scheme_disable (SCHEME_HTTPS);
-          logprintf (LOG_NOTQUIET,
-                     _("Disabling SSL due to encountered errors.\n"));
-          return SSLINITFAILED;
-        }
-    }
-#endif /* HAVE_SSL */
-
-  /* Initialize certain elements of struct http_stat.  */
-  hs->len = 0;
-  hs->contlen = -1;
-  hs->res = -1;
-  hs->rderrmsg = NULL;
-  hs->newloc = NULL;
-  xfree(hs->remote_time);
-  hs->error = NULL;
-  hs->message = NULL;
-
-  conn = u;
+  struct request *req;
 
   /* Prepare the request to send. */
   {
