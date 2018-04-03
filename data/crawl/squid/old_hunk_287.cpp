namespace Security
{

// The Transport Layer Security (TLS) Protocol, Version 1.2

/// TLS Record Layer's content types from RFC 5246 Section 6.2.1
enum ContentType {
    ctChangeCipherSpec = 20,
    ctAlert = 21,
    ctHandshake = 22,
    ctApplicationData = 23
};

/// TLS Record Layer's protocol version from RFC 5246 Section 6.2.1
struct ProtocolVersion
{
    explicit ProtocolVersion(BinaryTokenizer &tk);

    /// XXX: TlsDetails use "int" to manipulate version information.
    /// TODO: Use ProtocolVersion in TlsDetails and printTlsVersion().
    int toNumberXXX() const { return (vMajor << 8) | vMinor; }

    BinaryTokenizerContext context; ///< parsing context for debugging

    // the "v" prefix works around environments that #define major and minor
    uint8_t vMajor;
    uint8_t vMinor;
};

/// TLS Record Layer's frame from RFC 5246 Section 6.2.1.
struct TLSPlaintext
{
    explicit TLSPlaintext(BinaryTokenizer &tk);

    BinaryTokenizerContext context; ///< parsing context for debugging

    uint8_t type; ///< Rfc5246::ContentType
    ProtocolVersion version;
    uint16_t length;
    SBuf fragment; ///< exactly length bytes
};

/// draft-hickman-netscape-ssl-00. Section 4.1. SSL Record Header Format
struct Sslv2Record
{
    explicit Sslv2Record(BinaryTokenizer &tk);

    BinaryTokenizerContext context; ///< parsing context for debugging

    uint16_t length;
    SBuf fragment;
};

/// TLS Handshake protocol's handshake types from RFC 5246 Section 7.4
enum HandshakeType {
    hskClientHello = 1,
    hskServerHello = 2,
    hskCertificate = 11,
    hskServerHelloDone = 14
};

/// TLS Handshake Protocol frame from RFC 5246 Section 7.4.
struct Handshake
{
    explicit Handshake(BinaryTokenizer &tk);

    BinaryTokenizerContext context; ///< parsing context for debugging

    uint32_t msg_type: 8; ///< HandshakeType
    uint32_t length: 24;
    SBuf body; ///< Handshake Protocol message, exactly length bytes
};

/// TLS Alert protocol frame from RFC 5246 Section 7.2.
struct Alert
{
    explicit Alert(BinaryTokenizer &tk);


    bool fatal() const { return level == 2; }

    BinaryTokenizerContext context; ///< parsing context for debugging

    uint8_t level; ///< warning or fatal
    uint8_t description; ///< close_notify, unexpected_message, etc.
};

/// TLS Hello Extension from RFC 5246 Section 7.4.1.4.
struct Extension
{
    explicit Extension(BinaryTokenizer &tk);

    BinaryTokenizerContext context; ///< parsing context for debugging

    uint16_t type;
    uint16_t length; // XXX just use SBuf!
    SBuf body;
};

#define SQUID_TLS_RANDOM_SIZE 32

class TlsDetails: public RefCountable
{
public:
