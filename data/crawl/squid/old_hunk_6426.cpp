void
sig_intr(int sig)
{
    printf("\rWaiting for open connections to finish...\n");
    signal(sig, SIG_DFL);
}

int
open_http_socket(void)
{
    int s;
