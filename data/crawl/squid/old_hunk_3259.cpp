const char * obtain_challenge(void);
void manage_request(void);


#if DEBUG
char error_messages_buffer[BUFFER_SIZE];
#endif

char load_balance = 0, protocol_pedantic = 0;
#if NTLM_FAIL_OPEN
char last_ditch_enabled = 0;
#endif

dc *controllers = NULL;
int numcontrollers = 0;
dc *current_dc;

char smb_error_buffer[1000];

/* signal handler to be invoked when the authentication operation
 * times out */
static char got_timeout = 0;
static void
timeout_during_auth(int signum)
{
    dc_disconnect();
}

/* makes a null-terminated string upper-case. Changes CONTENTS! */
static void
uc(char *string)
{
    char *p = string, c;
    while ((c = *p)) {
        *p = xtoupper(c);
        p++;
    }
}

/* makes a null-terminated string lower-case. Changes CONTENTS! */
static void
lc(char *string)
{
    char *p = string, c;
    while ((c = *p)) {
        *p = xtolower(c);
        p++;
    }
}


void
send_bh_or_ld(char const *bhmessage, ntlm_authenticate * failedauth, int authlen)
{
#if NTLM_FAIL_OPEN
    char *creds = NULL;
    if (last_ditch_enabled) {
        creds = fetch_credentials(failedauth, authlen);
        if (creds) {
            lc(creds);
            SEND2("LD %s", creds);
        } else {
            SEND("NA last-ditch on, but no credentials");
        }
