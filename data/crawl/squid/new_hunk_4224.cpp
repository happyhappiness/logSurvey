    comm_close(fd());
}

/** Called to initiate (and possibly complete) closing of the context.
 * The underlying socket may be already closed */
void
ClientSocketContext::initiateClose(const char *reason)
{
