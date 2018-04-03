    FtpWriteForwardedReply(context, reply, call);
}

/// writes FTP error response with given status and reply-derived error details
static void
FtpWriteErrorReply(ClientSocketContext *context, const HttpReply *reply, const int status)
