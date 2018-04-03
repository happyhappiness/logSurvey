    buildTitleUrl();
    debugs(9, 5, HERE << "FD " << ctrl.conn->fd << " : host=" << request->GetHost() <<
           ", path=" << request->urlpath << ", user=" << user << ", passwd=" << password);
    state = BEGIN;
    Ftp::Client::start();
}

/* ====================================================================== */

void
Ftp::Gateway::handleControlReply()
{
    Ftp::Client::handleControlReply();
    if (ctrl.message == NULL)
        return; // didn't get complete reply yet

    /* Copy the message except for the last line to cwd_message to be
     * printed in error messages.
     */
    for (wordlist *w = ctrl.message; w && w->next; w = w->next) {
        cwd_message.append('\n');
        cwd_message.append(w->key);
    }

    FTP_SM_FUNCS[state] (this);
}

/* ====================================================================== */

static void
ftpReadWelcome(Ftp::Gateway * ftpState)
{
    int code = ftpState->ctrl.replycode;
    debugs(9, 3, HERE);
