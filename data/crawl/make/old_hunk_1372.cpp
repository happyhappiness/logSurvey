#include <fibdef.h>
#include "vmsdir.h"

DIR *opendir(char *dspec)
{
  static struct FAB *dfab;
  struct NAM *dnam;
  char *searchspec;

  if ((dfab = (struct FAB *)xmalloc(sizeof (struct FAB))) == NULL) {
    printf("Error mallocing for FAB\n");
    return(NULL);
  }
  if ((dnam = (struct NAM *)xmalloc(sizeof (struct NAM))) == NULL) {
    printf("Error mallocing for NAM\n");
    free(dfab);
    return(NULL);
  }
  if ((searchspec = (char *)xmalloc(MAXNAMLEN+1)) == NULL) {
    printf("Error mallocing for searchspec\n");
    free(dfab);
    free(dnam);
    return(NULL);
  }

  sprintf(searchspec,"%s*.*;",dspec);

  *dfab = cc$rms_fab;
  dfab->fab$l_fna = searchspec;
  dfab->fab$b_fns = strlen(searchspec);
  dfab->fab$l_nam = dnam;

  *dnam = cc$rms_nam;
  dnam->nam$l_esa = searchspec;
  dnam->nam$b_ess = MAXNAMLEN;

  if (!(sys$parse(dfab) & 1)) {
    free(dfab);
    free(dnam);
    free(searchspec);
    return(NULL);
  }

  return(dfab);
}

#include <ctype.h>
#define uppercasify(str) { char *tmp; for(tmp = (str); *tmp != '\0'; tmp++) if(islower(*tmp)) *tmp = toupper(*tmp); }

struct direct *readdir(DIR *dfd)
{
  static struct direct *dentry;
  static char resultspec[MAXNAMLEN+1];
  int i;

  if ((dentry = (struct direct *)xmalloc(sizeof (struct direct))) == NULL) {
    printf("Error mallocing for direct\n");
    return(NULL);
  }

  dfd->fab$l_nam->nam$l_rsa = resultspec;
  dfd->fab$l_nam->nam$b_rss = MAXNAMLEN;

  if (debug_flag)
    printf(".");

  if (!((i = sys$search(dfd)) & 1)) {
    if (debug_flag)
      printf("sys$search failed with %d\n", i);
    free(dentry);
    return(NULL);
  }

  dentry->d_off = 0;
  if (dfd->fab$l_nam->nam$w_fid == 0)
    dentry->d_fileno = 1;
  else dentry->d_fileno = dfd->fab$l_nam->nam$w_fid[0]
			 +dfd->fab$l_nam->nam$w_fid[1]<<16;
  dentry->d_reclen = sizeof (struct direct);
/*
  if (!strcmp(dfd->fab$l_nam->nam$l_type,".DIR"))
    dentry->d_namlen = dfd->fab$l_nam->nam$b_name;
  else
*/
    dentry->d_namlen = dfd->fab$l_nam->nam$b_name+dfd->fab$l_nam->nam$b_type;
  strncpy(dentry->d_name,dfd->fab$l_nam->nam$l_name,dentry->d_namlen);
  dentry->d_name[dentry->d_namlen] = '\0';
  uppercasify(dentry->d_name);
/*  uvUnFixRCSSeparator(dentry->d_name);*/

  return(dentry);
}

closedir(DIR *dfd)
{
  if (dfd != NULL) {
    if (dfd->fab$l_nam != NULL)
      free(dfd->fab$l_nam->nam$l_esa);
    free(dfd->fab$l_nam);
    free(dfd);
  }
}

char *getwd(char *cwd)
{
  static char buf[512];

    if (cwd)
      return(getcwd(cwd,512));
    else
      return(getcwd(buf,512));
}

int
