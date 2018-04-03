int
w32_kill(int pid, int sig)
{
  return ((process_kill(pid, sig) == TRUE) ? 0 : -1);
}
#endif /* WINDOWS32 */

