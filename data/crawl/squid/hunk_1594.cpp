 Ssl::CertificateStorageAction::Pointer Ssl::CertificateStorageAction::Create(const Mgr::Command::Pointer &cmd) STUB_RETSTATREF(Ssl::CertificateStorageAction::Pointer)
 void Ssl::CertificateStorageAction::dump(StoreEntry *sentry) STUB
 void Ssl::GlobalContextStorage::addLocalStorage(Ip::Address const & address, size_t size_of_store) STUB
-Ssl::LocalContextStorage & Ssl::GlobalContextStorage::getLocalStorage(Ip::Address const & address)
-{ fatal(STUB_API " required"); static Ssl::LocalContextStorage v(0,0); return v; }
+Ssl::LocalContextStorage *Ssl::GlobalContextStorage::getLocalStorage(Ip::Address const & address)
+{ fatal(STUB_API " required"); static Ssl::LocalContextStorage v(0,0); return &v; }
 void Ssl::GlobalContextStorage::reconfigureStart() STUB
 //Ssl::GlobalContextStorage Ssl::TheGlobalContextStorage;
 