//Ssl::CertificateStorageAction::CertificateStorageAction(const Mgr::Command::Pointer &cmd) STUB
Ssl::CertificateStorageAction::Pointer Ssl::CertificateStorageAction::Create(const Mgr::Command::Pointer &cmd) STUB_RETSTATREF(Ssl::CertificateStorageAction::Pointer)
void Ssl::CertificateStorageAction::dump(StoreEntry *sentry) STUB
Ssl::LocalContextStorage::Item::Item(SSL_CTX * aSsl_ctx, std::string const & aName) STUB
Ssl::LocalContextStorage::Item::~Item() STUB
Ssl::LocalContextStorage::LocalContextStorage(size_t aMax_memory) STUB
Ssl::LocalContextStorage::~LocalContextStorage() STUB
void Ssl::LocalContextStorage::SetSize(size_t aMax_memory) STUB
SSL_CTX * Ssl::LocalContextStorage::add(char const * host_name, SSL_CTX * ssl_ctx) STUB_RETVAL(NULL)
SSL_CTX * Ssl::LocalContextStorage::find(char const * host_name) STUB_RETVAL(NULL)
void Ssl::LocalContextStorage::remove(char const * host_name) STUB
//Ssl::GlobalContextStorage::GlobalContextStorage() STUB
//Ssl::GlobalContextStorage::~GlobalContextStorage() STUB
void Ssl::GlobalContextStorage::addLocalStorage(Ip::Address const & address, size_t size_of_store) STUB
Ssl::LocalContextStorage & Ssl::GlobalContextStorage::getLocalStorage(Ip::Address const & address)
{ fatal(STUB_API " required"); static Ssl::LocalContextStorage v(0); return v; }
void Ssl::GlobalContextStorage::reconfigureStart() STUB
//Ssl::GlobalContextStorage Ssl::TheGlobalContextStorage;
