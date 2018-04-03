 * done by the upper layers.
 */
int
storeCossDirCheckObj(SwapDir *SD, const StoreEntry *e)
{
  /* Check if the object is a special object, we can't cache these */
  if (EBIT_TEST(e->flags, ENTRY_SPECIAL))
      return -1;

  /* Otherwise, we're ok */
  /* Return 900 (90%) load */
  return 900;
}
     
/* ========== LOCAL FUNCTIONS ABOVE, GLOBAL FUNCTIONS BELOW ========== */

void
storeCossDirStats(SwapDir *SD, StoreEntry * sentry)
{
    CossInfo *cs = (CossInfo *)SD->fsdata;
    
    storeAppendPrintf(sentry, "\n");
    storeAppendPrintf(sentry, "Maximum Size: %d KB\n", SD->max_size);
    storeAppendPrintf(sentry, "Current Size: %d KB\n", SD->cur_size);
    storeAppendPrintf(sentry, "Percent Used: %0.2f%%\n",
      100.0 * SD->cur_size / SD->max_size);
    storeAppendPrintf(sentry, "Number of object collisions: %d\n", (int)cs->numcollisions);
#if 0
    /* is this applicable? I Hope not .. */
    storeAppendPrintf(sentry, "Filemap bits in use: %d of %d (%d%%)\n",
      SD->map->n_files_in_map, SD->map->max_n_files,
      percent(SD->map->n_files_in_map, SD->map->max_n_files));
#endif
    storeAppendPrintf(sentry, "Flags:");
    if (SD->flags.selected)
        storeAppendPrintf(sentry, " SELECTED");
    if (SD->flags.read_only)
        storeAppendPrintf(sentry, " READ-ONLY");
    storeAppendPrintf(sentry, "\n");
}

static void
storeCossDirParse(SwapDir *sd, int index, char *path)
{
    char *token;
    unsigned int i;
