} while (0)
#endif /* def __VMS [else] */

static struct request *
initialize_request (struct url *u, struct http_stat *hs, int *dt, struct url *proxy,
                    bool inhibit_keep_alive, bool *basic_auth_finished,
                    wgint *body_data_size, char **user, char **passwd, uerr_t *ret)
{
  bool head_only = !!(*dt & HEAD_ONLY);
  struct request *req;

  /* Prepare the request to send. */
  {
