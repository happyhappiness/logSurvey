password_conversation(int num_msg, PAM_CONV_FUNC_CONST_PARM struct pam_message **msg, struct pam_response **resp, void *appdata_ptr)
{
    if (num_msg != 1 || msg[0]->msg_style != PAM_PROMPT_ECHO_OFF) {
        fprintf(stderr, "ERROR: Unexpected PAM converstaion '%d/%s'\n", msg[0]->msg_style, msg[0]->msg);
        return PAM_CONV_ERR;
    }
#if _SQUID_SOLARIS_
