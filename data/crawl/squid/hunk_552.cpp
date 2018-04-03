 #include <openssl/bio.h>
 #endif
 #include <string>
+#include <type_traits>
+
+// TODO: Move BinaryTokenizer to its own set of files outside of Ssl namespace.
+
+/// Safely extracts byte-oriented (i.e., non-textual) fields from raw input.
+/// Supports commit points for atomic incremental parsing of multi-part fields.
+/// Throws InsufficientInput when more input is needed to parse the next field.
+/// Throws on errors.
+class BinaryTokenizer
+{
+public:
+    class InsufficientInput {}; // thrown when a method runs out of data
+    typedef uint64_t size_type; // enough for the largest supported offset
+
+    BinaryTokenizer();
+    explicit BinaryTokenizer(const SBuf &data);
+
+    /// restart parsing from the very beginning
+    /// this method is for using one BinaryTokenizer to parse independent inputs
+    void reset(const SBuf &data);
+
+    /// change input without changing parsing state
+    /// this method avoids append overheads during incremental parsing
+    void reinput(const SBuf &data) { data_ = data; }
+
+    /// make progress: future parsing failures will not rollback beyond this point
+    void commit();
+
+    /// resume [incremental] parsing from the last commit point
+    void rollback();
+
+    /// no more bytes to parse or skip
+    bool atEnd() const;
+
+    /// parse a single-byte unsigned integer
+    uint8_t uint8(const char *description);
+
+    // parse a two-byte unsigned integer
+    uint16_t uint16(const char *description);
+
+    // parse a three-byte unsigned integer (returned as uint32_t)
+    uint32_t uint24(const char *description);
+
+    // parse a four-byte unsigned integer
+    uint32_t uint32(const char *description);
+
+    /// parse size consecutive bytes as an opaque blob
+    SBuf area(uint64_t size, const char *description);
+
+    /// ignore the next size bytes
+    void skip(uint64_t size, const char *description);
+
+    /// yet unparsed bytes
+    SBuf leftovers() const { return data_.substr(parsed_); }
+
+    const char *context; ///< simplifies debugging
+
+protected:
+    uint32_t octet();
+    void want(uint64_t size, const char *description) const;
+    void got(uint32_t value, uint64_t size, const char *description) const;
+    void got(const SBuf &value, uint64_t size, const char *description) const;
+    void skipped(uint64_t size, const char *description) const;
+
+private:
+    SBuf data_;
+    uint64_t parsed_; ///< number of data bytes parsed or skipped
+    uint64_t syncPoint_; ///< where to re-start the next parsing attempt
+};
+
 
 namespace Ssl
 {
+
+// The Transport Layer Security (TLS) Protocol, Version 1.2
+
+// TODO: Consider removing this namespace. The idea was to encapsulate various
+// RFC 5246 types defined using the naming scheme from the RFC rather than
+// following Squid naming conventions. However, using these names in other code
+// may make that code inconsistent. Besides, we are running into some C++ naming
+// limits.
+namespace Rfc5246
+{
+
+/// Helper class to debug parsing of various TLS structures
+class FieldGroup
+{
+public:
+    FieldGroup(BinaryTokenizer &tk, const char *description); ///< starts parsing
+
+    void commit(BinaryTokenizer &tk); ///< commits successful parsing results
+};
+
+/// TLS Record Layer's content types from RFC 5246 Section 6.2.1
+enum ContentType {
+    ctChangeCipherSpec = 20,
+    ctAlert = 21,
+    ctHandshake = 22,
+    ctApplicationData = 23
+};
+
+/// TLS Record Layer's protocol version from RFC 5246 Section 6.2.1
+struct ProtocolVersion
+{
+    explicit ProtocolVersion(BinaryTokenizer &tk);
+
+    // the "v" prefix works around environments that #define major and minor
+    uint8_t vMajor;
+    uint8_t vMinor;
+};
+
+/// TLS Record Layer's frame from RFC 5246 Section 6.2.1.
+struct TLSPlaintext: public FieldGroup
+{
+    explicit TLSPlaintext(BinaryTokenizer &tk);
+
+    uint8_t type; ///< Rfc5246::ContentType
+    ProtocolVersion version;
+    uint16_t length;
+    SBuf fragment; ///< exactly length bytes
+};
+
+/// TLS Handshake protocol's handshake types from RFC 5246 Section 7.4
+enum HandshakeType {
+    hskServerHello = 2,
+    hskCertificate = 11,
+    hskServerHelloDone = 14
+};
+
+/// TLS Handshake Protocol frame from RFC 5246 Section 7.4.
+struct Handshake: public FieldGroup
+{
+    explicit Handshake(BinaryTokenizer &tk);
+
+    uint32_t msg_type: 8; ///< HandshakeType
+    uint32_t length: 24;
+    SBuf body; ///< Handshake Protocol message, exactly length bytes
+};
+
+/// TLS Alert protocol frame from RFC 5246 Section 7.2.
+struct Alert: public FieldGroup
+{
+    explicit Alert(BinaryTokenizer &tk);
+    uint8_t level; ///< warning or fatal
+    uint8_t description; ///< close_notify, unexpected_message, etc.
+};
+
+/// Like a Pascal "length-first" string but with a 3-byte length field.
+/// Used for (undocumented in RRC 5246?) Certificate and ASN1.Cert encodings.
+struct P24String: public FieldGroup
+{
+    explicit P24String(BinaryTokenizer &tk, const char *description);
+
+    uint32_t length;  // bytes in body (stored using 3 bytes, not 4!)
+    SBuf body; ///< exactly length bytes
+};
+
+} // namespace Rfc5246
+
+
+/// Incremental SSL Handshake parser.
 class HandshakeParser {
 public:
     /// The parsing states
     typedef enum {atHelloNone = 0, atHelloStarted, atHelloReceived, atCertificatesReceived, atHelloDoneReceived, atNstReceived, atCcsReceived, atFinishReceived} ParserState;
 
-    /// TLS record protocol, content types, RFC5246 section 6.2.1
-    typedef enum {ctNone = 0, ctChangeCipherSpec = 20, ctAlert = 21, ctHandshake = 22, ctApplicationData} ContentType;
-    /// TLS Handshake protocol, handshake types, RFC5246  section 7.4
-    typedef enum {hskNone = 0,  hskServerHello = 2, shkNewSessionTicket = 4, hskCertificate = 11, hskServerHelloDone = 14, hskFinished = 20} HandshakeType;
-
-    HandshakeParser(): state(atHelloNone), currentContentType(ctNone), unParsedContent(0), parsingPos(0), currentMsg(0), currentMsgSize(0), certificatesMsgPos(0), certificatesMsgSize(0), ressumingSession(false), parseDone(false), parseError(false) {}
+    HandshakeParser(): state(atHelloNone), ressumingSession(false), parseDone(false), parseError(false), currentContentType(0), unParsedContent(0), parsingPos(0), currentMsg(0), currentMsgSize(0), certificatesMsgPos(0), certificatesMsgSize(0) {}
 
-    /// Parses the SSL Server Hello records stored in data.
-    /// Return false if the hello messages are not complete (HelloDone 
-    /// or Finished handshake messages are not received)
-    /// On parse error, return false and sets the parseError member to true.
-    bool parseServerHello(const unsigned char *data, size_t dataSize);
+    /// Parses the initial sequence of raw bytes sent by the SSL server.
+    /// Returns true upon successful completion (HelloDone or Finished received).
+    /// Otherwise, returns false (and sets parseError to true on errors).
+    bool parseServerHello(const SBuf &data);
 
-    /// Parse server certificates message and store the certificate to serverCertificates list
-    bool parseServerCertificates(Ssl::X509_STACK_Pointer &serverCertificates, const unsigned char *msg, size_t size);
+    Ssl::X509_STACK_Pointer serverCertificates; ///< parsed certificates chain
 
     ParserState state; ///< current parsing state.
 
-    ContentType currentContentType; ///< The current SSL record content type
+    bool ressumingSession; ///< True if this is a resumming session
+
+    bool parseDone; ///< The parser finishes its job
+    bool parseError; ///< Set to tru by parse on parse error.
+
+private:
+    unsigned int currentContentType; ///< The current SSL record content type
     size_t unParsedContent; ///< The size of current SSL record, which is not parsed yet
     size_t parsingPos; ///< The parsing position from the beginning of parsed data
     size_t currentMsg; ///< The current handshake message possition from the beginning of parsed data
     size_t currentMsgSize; ///< The current handshake message size.
 
     size_t certificatesMsgPos; ///< The possition of certificates message from the beggining of parsed data
     size_t certificatesMsgSize; ///< The size of certificates message
-    bool ressumingSession; ///< True if this is a resumming session
-
-    bool parseDone; ///< The parser finishes its job
-    bool parseError; ///< Set to tru by parse on parse error.
 
 private:
-    /// Do nothing if there are unparsed data from existing SSL record
-    /// else parses the next SSL record.
-    /// Return false if the next SSL record is not complete.
-    bool parseNextContentRecord(const unsigned char *msg, size_t size);
-    /// Consumes the current SSL record and set the parsingPos to the next
-    bool skipContentDataRecord(const unsigned char *msg, size_t size);
-    /// Parses the next handshake message in current SSL record
-    HandshakeType parseNextHandshakeMessage(const unsigned char *msg, size_t size);
+    void parseServerHelloTry();
+
+    void parseRecord();
+    void parseMessages();
+
+    void parseChangeCipherCpecMessage();
+    void parseAlertMessage();
+    void parseHandshakeMessage();
+    void parseApplicationDataMessage();
+    void skipMessage(const char *msgType);
+
+    void parseServerCertificates(const SBuf &raw);
+    static X509 *ParseCertificate(const SBuf &raw);
+
+    /// concatenated TLSPlaintext.fragments of TLSPlaintext.type
+    SBuf fragments;
+
+    BinaryTokenizer tkRecords; // TLS record layer (parsing uninterpreted data)
+    BinaryTokenizer tkMessages; // TLS message layer (parsing fragments)
 };
 
 /// BIO source and sink node, handling socket I/O and monitoring SSL state
