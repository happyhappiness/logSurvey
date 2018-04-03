}


#ifndef HAVE_STRERROR
#undef  strerror
char *
strerror (int errnum)
{
