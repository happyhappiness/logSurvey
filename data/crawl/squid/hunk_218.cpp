 #ifndef SQUID_SECURITY_HANDSHAKE_H
 #define SQUID_SECURITY_HANDSHAKE_H
 
-#include "fd.h"
+#include "anyp/ProtocolVersion.h"
+#include "base/YesNoNone.h"
 #include "parser/BinaryTokenizer.h"
-#include "sbuf/SBuf.h"
 #if USE_OPENSSL
 #include "ssl/gadgets.h"
 #endif
 
+#include <unordered_set>
+
 namespace Security
 {
 
-// The Transport Layer Security (TLS) Protocol, Version 1.2
-
-/// Helper class to debug parsing of various TLS structures
-class FieldGroup
+class TlsDetails: public RefCountable
 {
 public:
-    FieldGroup(BinaryTokenizer &tk, const char *description); ///< starts parsing
-
-    void commit(BinaryTokenizer &tk); ///< commits successful parsing results
-};
-
-/// TLS Record Layer's content types from RFC 5246 Section 6.2.1
-enum ContentType {
-    ctChangeCipherSpec = 20,
-    ctAlert = 21,
-    ctHandshake = 22,
-    ctApplicationData = 23
-};
-
-/// TLS Record Layer's protocol version from RFC 5246 Section 6.2.1
-struct ProtocolVersion
-{
-    explicit ProtocolVersion(BinaryTokenizer &tk);
-
-    // the "v" prefix works around environments that #define major and minor
-    uint8_t vMajor;
-    uint8_t vMinor;
-};
-
-/// TLS Record Layer's frame from RFC 5246 Section 6.2.1.
-struct TLSPlaintext: public FieldGroup
-{
-    explicit TLSPlaintext(BinaryTokenizer &tk);
-
-    uint8_t type; ///< Rfc5246::ContentType
-    ProtocolVersion version;
-    uint16_t length;
-    SBuf fragment; ///< exactly length bytes
-};
-
-/// TLS Handshake protocol's handshake types from RFC 5246 Section 7.4
-enum HandshakeType {
-    hskServerHello = 2,
-    hskCertificate = 11,
-    hskServerHelloDone = 14
-};
-
-/// TLS Handshake Protocol frame from RFC 5246 Section 7.4.
-struct Handshake: public FieldGroup
-{
-    explicit Handshake(BinaryTokenizer &tk);
-
-    uint32_t msg_type: 8; ///< HandshakeType
-    uint32_t length: 24;
-    SBuf body; ///< Handshake Protocol message, exactly length bytes
+    typedef RefCount<TlsDetails> Pointer;
+
+    TlsDetails();
+    /// Prints to os stream a human readable form of TlsDetails object
+    std::ostream & print(std::ostream &os) const;
+
+    AnyP::ProtocolVersion tlsVersion; ///< The TLS hello message version
+    AnyP::ProtocolVersion tlsSupportedVersion; ///< The requested/used TLS version
+    bool compressionSupported; ///< The requested/used compressed  method
+    SBuf serverName; ///< The SNI hostname, if any
+    bool doHeartBeats;
+    bool tlsTicketsExtension; ///< whether TLS tickets extension is enabled
+    bool hasTlsTicket; ///< whether a TLS ticket is included
+    bool tlsStatusRequest; ///< whether the TLS status request extension is set
+    bool unsupportedExtensions; ///< whether any unsupported by Squid extensions are used
+    SBuf tlsAppLayerProtoNeg; ///< The value of the TLS application layer protocol extension if it is enabled
+    /// The client random number
+    SBuf clientRandom;
+    SBuf sessionId;
+
+    typedef std::unordered_set<uint16_t> Ciphers;
+    Ciphers ciphers;
 };
 
-/// TLS Alert protocol frame from RFC 5246 Section 7.2.
-struct Alert: public FieldGroup
+inline
+std::ostream &operator <<(std::ostream &os, Security::TlsDetails const &details)
 {
-    explicit Alert(BinaryTokenizer &tk);
-    uint8_t level; ///< warning or fatal
-    uint8_t description; ///< close_notify, unexpected_message, etc.
-};
+    return details.print(os);
+}
 
-/// Like a Pascal "length-first" string but with a 3-byte length field.
-/// Used for (undocumented in RRC 5246?) Certificate and ASN1.Cert encodings.
-struct P24String: public FieldGroup
+/// Incremental TLS/SSL Handshake parser.
+class HandshakeParser
 {
-    explicit P24String(BinaryTokenizer &tk, const char *description);
-
-    uint32_t length;  // bytes in body (stored using 3 bytes, not 4!)
-    SBuf body; ///< exactly length bytes
-};
-
-/// Incremental SSL Handshake parser.
-class HandshakeParser {
 public:
     /// The parsing states
     typedef enum {atHelloNone = 0, atHelloStarted, atHelloReceived, atCertificatesReceived, atHelloDoneReceived, atNstReceived, atCcsReceived, atFinishReceived} ParserState;
 
-    HandshakeParser(): state(atHelloNone), ressumingSession(false), parseDone(false), parseError(false), currentContentType(0), unParsedContent(0), parsingPos(0), currentMsg(0), currentMsgSize(0), certificatesMsgPos(0), certificatesMsgSize(0) {}
+    HandshakeParser();
 
-    /// Parses the initial sequence of raw bytes sent by the SSL server.
-    /// Returns true upon successful completion (HelloDone or Finished received).
-    /// Otherwise, returns false (and sets parseError to true on errors).
-    bool parseServerHello(const SBuf &data);
+    /// Parses the initial sequence of raw bytes sent by the TLS/SSL agent.
+    /// Returns true upon successful completion (e.g., got HelloDone).
+    /// Returns false if more data is needed.
+    /// Throws on errors.
+    bool parseHello(const SBuf &data);
+
+    TlsDetails::Pointer details; ///< TLS handshake meta info or nil.
 
 #if USE_OPENSSL
     Ssl::X509_STACK_Pointer serverCertificates; ///< parsed certificates chain
 #endif
 
     ParserState state; ///< current parsing state.
 
-    bool ressumingSession; ///< True if this is a resumming session
-
-    bool parseDone; ///< The parser finishes its job
-    bool parseError; ///< Set to tru by parse on parse error.
-
-private:
-    unsigned int currentContentType; ///< The current SSL record content type
-    size_t unParsedContent; ///< The size of current SSL record, which is not parsed yet
-    size_t parsingPos; ///< The parsing position from the beginning of parsed data
-    size_t currentMsg; ///< The current handshake message possition from the beginning of parsed data
-    size_t currentMsgSize; ///< The current handshake message size.
-
-    size_t certificatesMsgPos; ///< The possition of certificates message from the beggining of parsed data
-    size_t certificatesMsgSize; ///< The size of certificates message
+    bool resumingSession; ///< True if this is a resuming session
 
 private:
-    void parseServerHelloTry();
-
+    bool isSslv2Record(const SBuf &raw) const;
     void parseRecord();
+    void parseModernRecord();
+    void parseVersion2Record();
     void parseMessages();
 
     void parseChangeCipherCpecMessage();
