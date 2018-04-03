#include <openssl/bio.h>
#endif
#include <string>

namespace Ssl
{
class HandshakeParser {
public:
    /// The parsing states
    typedef enum {atHelloNone = 0, atHelloStarted, atHelloReceived, atCertificatesReceived, atHelloDoneReceived, atNstReceived, atCcsReceived, atFinishReceived} ParserState;

    /// TLS record protocol, content types, RFC5246 section 6.2.1
    typedef enum {ctNone = 0, ctChangeCipherSpec = 20, ctAlert = 21, ctHandshake = 22, ctApplicationData} ContentType;
    /// TLS Handshake protocol, handshake types, RFC5246  section 7.4
    typedef enum {hskNone = 0,  hskServerHello = 2, shkNewSessionTicket = 4, hskCertificate = 11, hskServerHelloDone = 14, hskFinished = 20} HandshakeType;

    HandshakeParser(): state(atHelloNone), currentContentType(ctNone), unParsedContent(0), parsingPos(0), currentMsg(0), currentMsgSize(0), certificatesMsgPos(0), certificatesMsgSize(0), ressumingSession(false), parseDone(false), parseError(false) {}

    /// Parses the SSL Server Hello records stored in data.
    /// Return false if the hello messages are not complete (HelloDone 
    /// or Finished handshake messages are not received)
    /// On parse error, return false and sets the parseError member to true.
    bool parseServerHello(const unsigned char *data, size_t dataSize);

    /// Parse server certificates message and store the certificate to serverCertificates list
    bool parseServerCertificates(Ssl::X509_STACK_Pointer &serverCertificates, const unsigned char *msg, size_t size);

    ParserState state; ///< current parsing state.

    ContentType currentContentType; ///< The current SSL record content type
    size_t unParsedContent; ///< The size of current SSL record, which is not parsed yet
    size_t parsingPos; ///< The parsing position from the beginning of parsed data
    size_t currentMsg; ///< The current handshake message possition from the beginning of parsed data
    size_t currentMsgSize; ///< The current handshake message size.

    size_t certificatesMsgPos; ///< The possition of certificates message from the beggining of parsed data
    size_t certificatesMsgSize; ///< The size of certificates message
    bool ressumingSession; ///< True if this is a resumming session

    bool parseDone; ///< The parser finishes its job
    bool parseError; ///< Set to tru by parse on parse error.

private:
    /// Do nothing if there are unparsed data from existing SSL record
    /// else parses the next SSL record.
    /// Return false if the next SSL record is not complete.
    bool parseNextContentRecord(const unsigned char *msg, size_t size);
    /// Consumes the current SSL record and set the parsingPos to the next
    bool skipContentDataRecord(const unsigned char *msg, size_t size);
    /// Parses the next handshake message in current SSL record
    HandshakeType parseNextHandshakeMessage(const unsigned char *msg, size_t size);
};

/// BIO source and sink node, handling socket I/O and monitoring SSL state
