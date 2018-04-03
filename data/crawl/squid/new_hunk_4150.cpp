// A Token Element was invalid (e.g. improper length or value)
#define SPNEGO_E_INVALID_ELEMENT       -13

    /* Miscelaneous API Functions */

// Frees opaque data
    void spnegoFreeData( SPNEGO_TOKEN_HANDLE hSpnegoToken );

// Initializes SPNEGO_TOKEN structure from DER encoded binary data
    int spnegoInitFromBinary( unsigned char* pbTokenData, unsigned long ulLength, SPNEGO_TOKEN_HANDLE* phSpnegoToken );

// Initializes SPNEGO_TOKEN structure for a NegTokenInit type using the
// supplied parameters
    int spnegoCreateNegTokenInit( SPNEGO_MECH_OID MechType,
                                  unsigned char ucContextFlags, unsigned char* pbMechToken,
                                  unsigned long ulMechTokenLen, unsigned char* pbMechTokenMIC,
                                  unsigned long ulMechTokenMIC, SPNEGO_TOKEN_HANDLE* phSpnegoToken );

// Initializes SPNEGO_TOKEN structure for a NegTokenTarg type using the
// supplied parameters
    int spnegoCreateNegTokenTarg( SPNEGO_MECH_OID MechType,
                                  SPNEGO_NEGRESULT spnegoNegResult, unsigned char* pbMechToken,
                                  unsigned long ulMechTokenLen, unsigned char* pbMechListMIC,
                                  unsigned long ulMechListMICLen, SPNEGO_TOKEN_HANDLE* phSpnegoToken );

// Copies binary representation of SPNEGO Data into user supplied buffer
    int spnegoTokenGetBinary( SPNEGO_TOKEN_HANDLE hSpnegoToken, unsigned char* pbTokenData,
                              unsigned long * pulDataLen );

// Returns SPNEGO Token Type
    int spnegoGetTokenType( SPNEGO_TOKEN_HANDLE hSpnegoToken, int * piTokenType );

    /* Reading an Init Token */

// Returns the Initial Mech Type in the MechList element in the NegInitToken.
    int spnegoIsMechTypeAvailable( SPNEGO_TOKEN_HANDLE hSpnegoToken, SPNEGO_MECH_OID MechOID, int * piMechTypeIndex );

// Returns the value from the context flags element in the NegInitToken as an unsigned long
    int spnegoGetContextFlags( SPNEGO_TOKEN_HANDLE hSpnegoToken, unsigned char* pucContextFlags );

    /* Reading a Response Token */

// Returns the value from the negResult element (Status code of GSS call - 0,1,2)
    int spnegoGetNegotiationResult( SPNEGO_TOKEN_HANDLE hSpnegoToken, SPNEGO_NEGRESULT* pnegResult );

// Returns the Supported Mech Type from the NegTokenTarg.
    int spnegoGetSupportedMechType( SPNEGO_TOKEN_HANDLE hSpnegoToken, SPNEGO_MECH_OID* pMechOID  );

    /* Reading either Token Type */

// Returns the actual Mechanism data from the token (this is what is passed into GSS-API functions
    int spnegoGetMechToken( SPNEGO_TOKEN_HANDLE hSpnegoToken, unsigned char* pbTokenData, unsigned long* pulDataLen );

// Returns the Message Integrity BLOB in the token
    int spnegoGetMechListMIC( SPNEGO_TOKEN_HANDLE hSpnegoToken, unsigned char* pbMICData, unsigned long* pulDataLen );

// C++ Specific
#if defined(__cplusplus)
}
#endif
#ifdef DEBUG
#include <stdio.h>
#define PRERR(...) fprintf(stderr, __VA_ARGS__)
#define LOG(x) PRERR x
#else
#define LOG(x)
#endif
#endif
