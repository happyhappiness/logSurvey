/* returns: 0 = no collision detected, otherwise = collision found => warn user for active attack */
int  SHA1DCFinal(unsigned char[20], SHA1_CTX*);

#if defined(__cplusplus)
}
#endif

#ifdef SHA1DC_CUSTOM_TRAILING_INCLUDE_SHA1_H
#include SHA1DC_CUSTOM_TRAILING_INCLUDE_SHA1_H
#endif

#endif
