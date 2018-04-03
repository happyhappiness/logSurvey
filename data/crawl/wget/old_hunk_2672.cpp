     // Value freshly allocated, free it when done.
     request_set_header (req, "Range",
                         aprintf ("bytes=%s-", number_to_static_string (hs->restval)),
			 rel_value);
   */

static void
request_set_header (struct request *req, char *name, char *value,
		    enum rp release_policy)
{
  struct request_header *hdr;
  int i;
