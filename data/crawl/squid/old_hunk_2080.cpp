//Ssl::GlobalContextStorage::~GlobalContextStorage() STUB
void Ssl::GlobalContextStorage::addLocalStorage(Ip::Address const & address, size_t size_of_store) STUB
Ssl::LocalContextStorage & Ssl::GlobalContextStorage::getLocalStorage(Ip::Address const & address)
    { fatal(STUB_API " required"); static Ssl::LocalContextStorage v(0); return v; }
void Ssl::GlobalContextStorage::reconfigureStart() STUB
//Ssl::GlobalContextStorage Ssl::TheGlobalContextStorage;
