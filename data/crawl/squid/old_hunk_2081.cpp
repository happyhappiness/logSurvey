#include "squid.h"
#include "fatal.h"

/* Stub File for the ssl/libsslsquid.la convenience library */

#define STUB_BASE "ssl/libsslsquid.la"

#define STUB { fatal(STUB_BASE " required."); }
#define STUB_RETVAL(x) { fatal(STUB_BASE " required."); return (x); }
#define STUB_RETREF(x) { fatal(STUB_BASE " required."); static x v; return v; }
#define STUB_RETREF2(x,y) { fatal(STUB_BASE " required."); static x v((y)); return v; }

#include "ssl/Config.h"
Ssl::Config::Config() STUB
Ssl::Config::~Config() STUB
Ssl::Config Ssl::TheConfig;

#include "ssl/context_storage.h"
//Ssl::CertificateStorageAction::CertificateStorageAction(const Mgr::Command::Pointer &cmd) STUB
Ssl::CertificateStorageAction::Pointer Ssl::CertificateStorageAction::Create(const Mgr::Command::Pointer &cmd) STUB_RETREF(Ssl::CertificateStorageAction::Pointer)
void Ssl::CertificateStorageAction::dump(StoreEntry *sentry) STUB
Ssl::LocalContextStorage::Item::Item(SSL_CTX * aSsl_ctx, std::string const & aName) STUB
Ssl::LocalContextStorage::Item::~Item() STUB
