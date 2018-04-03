    AuthUser *auth_user;
};

class ConnStateData;

class AuthScheme;

/* authenticate.c authenticate scheme routines typedefs */
/* TODO: this should be a generic cachemgr API type ? */
typedef void AUTHSSTATS(StoreEntry *);

/* subsumed by the C++ interface */
extern void authenticateAuthUserMerge(auth_user_t *, auth_user_t *);

extern void authenticateInit(authConfig *);
extern void authenticateShutdown(void);
extern int authenticateAuthUserInuse(auth_user_t * auth_user);

extern void authenticateFreeProxyAuthUserACLResults(void *data);
extern int authenticateActiveSchemeCount(void);
extern int authenticateSchemeCount(void);

extern void authenticateUserCacheRestart(void);
extern void authenticateOnCloseConnection(ConnStateData * conn);

#endif /* SQUID_AUTHENTICATE_H */
