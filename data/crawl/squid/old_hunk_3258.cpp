#if HAVE_ASSERT_H
#include <assert.h>
#endif

/* local functions */
void send_bh_or_ld(char const *bhmessage, ntlm_authenticate * failedauth, int authlen);
