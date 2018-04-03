#include "squid.h"

#if USE_SSL

#include "fatal.h"

/* Stub File for the ssl/libsslsquid.la convenience library */

#define STUB_API "ssl/libsslsquid.la"
#include "tests/STUB.h"


#include "ssl/Config.h"
Ssl::Config::Config() { printf("Ssl::Config::Config No implemented\n"); }
Ssl::Config::~Config() { printf("Ssl::Config::Config No implemented\n"); }
Ssl::Config Ssl::TheConfig;

#include "ssl/context_storage.h"
//Ssl::CertificateStorageAction::CertificateStorageAction(const Mgr::Command::Pointer &cmd) STUB
Ssl::CertificateStorageAction::Pointer Ssl::CertificateStorageAction::Create(const Mgr::Command::Pointer &cmd) STUB_RETSTATREF(Ssl::CertificateStorageAction::Pointer)
void Ssl::CertificateStorageAction::dump(StoreEntry *sentry) STUB
Ssl::LocalContextStorage::Item::Item(SSL_CTX * aSsl_ctx, std::string const & aName) STUB
Ssl::LocalContextStorage::Item::~Item() STUB
