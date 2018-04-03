 SSL_CTX * Ssl::LocalContextStorage::add(char const * host_name, SSL_CTX * ssl_ctx) STUB_RETVAL(NULL)
 SSL_CTX * Ssl::LocalContextStorage::find(char const * host_name) STUB_RETVAL(NULL)
 void Ssl::LocalContextStorage::remove(char const * host_name) STUB
-Ssl::GlobalContextStorage::GlobalContextStorage() STUB
-Ssl::GlobalContextStorage::~GlobalContextStorage() STUB
+//Ssl::GlobalContextStorage::GlobalContextStorage() STUB
+//Ssl::GlobalContextStorage::~GlobalContextStorage() STUB
 void Ssl::GlobalContextStorage::addLocalStorage(Ip::Address const & address, size_t size_of_store) STUB
-Ssl::LocalContextStorage & Ssl::GlobalContextStorage::getLocalStorage(Ip::Address const & address) STUB_RETREF2(Ssl::LocalContextStorage, 0)
+Ssl::LocalContextStorage & Ssl::GlobalContextStorage::getLocalStorage(Ip::Address const & address)
+    { fatal(STUB_API " required"); static Ssl::LocalContextStorage v(0); return v; }
 void Ssl::GlobalContextStorage::reconfigureStart() STUB
 //Ssl::GlobalContextStorage Ssl::TheGlobalContextStorage;
 
 #include "ssl/ErrorDetail.h"
 Ssl::ssl_error_t parseErrorString(const char *name) STUB_RETVAL(0)
-const char *Ssl::getErrorName(ssl_error_t value) STUB_RETVAL(NULL)
+//const char *Ssl::getErrorName(ssl_error_t value) STUB_RETVAL(NULL)
 Ssl::ErrorDetail::ErrorDetail(ssl_error_t err_no, X509 *cert) STUB
 Ssl::ErrorDetail::ErrorDetail(ErrorDetail const &) STUB
-const String & Ssl::ErrorDetail::toString() const STUB_RETREF(String)
+const String & Ssl::ErrorDetail::toString() const STUB_RETSTATREF(String)
 
 #include "ssl/support.h"
 SSL_CTX *sslCreateServerContext(const char *certfile, const char *keyfile, int version, const char *cipher, const char *options, const char *flags, const char *clientCA, const char *CAfile, const char *CApath, const char *CRLfile, const char *dhpath, const char *context) STUB_RETVAL(NULL)
 SSL_CTX *sslCreateClientContext(const char *certfile, const char *keyfile, int version, const char *cipher, const char *options, const char *flags, const char *CAfile, const char *CApath, const char *CRLfile) STUB_RETVAL(NULL)
 int ssl_read_method(int, char *, int) STUB_RETVAL(0)
 int ssl_write_method(int, const char *, int) STUB_RETVAL(0)
-void ssl_shutdown_method(int) STUB
+void ssl_shutdown_method(SSL *) STUB
 const char *sslGetUserEmail(SSL *ssl) STUB_RETVAL(NULL)
 // typedef char const *SSLGETATTRIBUTE(SSL *, const char *);
 // SSLGETATTRIBUTE sslGetUserAttribute;
