
CBDATA_CLASS_INIT(ACLFilledChecklist);

void
ACLFilledChecklist::checkCallback(allow_t answer)
{
    debugs(28, 5, HERE << this << " answer=" << answer);

    /* During reconfigure, we can end up not finishing call
     * sequences into the auth code */

    if (auth_user_request != NULL) {
        /* the filled_checklist lock */
        auth_user_request = NULL;
        /* it might have been connection based */
        if (conn()) {
            conn()->auth_user_request = NULL;
        }
    }

