/*
 * Copyright (C) 1996-2016 The Squid Software Foundation and contributors
 *
 * Squid software is distributed under GPLv2+ license and includes
 * contributions from numerous individuals and organizations.
 * Please see the COPYING and CONTRIBUTORS files for details.
 */

/* DEBUG: section 83    SSL-Bump Server/Peer negotiation */

#include "squid.h"
#include "security/Handshake.h"
#if USE_OPENSSL
#include "ssl/support.h"
#endif

#include <unordered_set>

namespace Security {
/*
 * The types below represent various SSL and TLS protocol elements. Most names
 * are based on RFC 5264 and RFC 6066 terminology. Objects of these explicit
 * types are stored or passed around. Other protocol elements are simply parsed
 * in-place, without declaring a corresponding explicit class.
 */

/// TLS Record Layer's content types from RFC 5246 Section 6.2.1
enum ContentType {
    ctChangeCipherSpec = 20,
    ctAlert = 21,
    ctHandshake = 22,
    ctApplicationData = 23
};

/// TLS Record Layer's frame from RFC 5246 Section 6.2.1.
class TLSPlaintext
{
public:
    explicit TLSPlaintext(Parser::BinaryTokenizer &tk);

    uint8_t type; ///< see ContentType
    AnyP::ProtocolVersion version; ///< Record Layer, not necessarily the negotiated TLS version;
    SBuf fragment; ///< possibly partial content
};

/// draft-hickman-netscape-ssl-00. Section 4.1. SSL Record Header Format
class Sslv2Record
{
public:
    explicit Sslv2Record(Parser::BinaryTokenizer &tk);

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
class Handshake
{
public:
    explicit Handshake(Parser::BinaryTokenizer &tk);

    uint8_t msg_type; ///< see HandshakeType
    SBuf msg_body; ///< Handshake Protocol message
};

/// TLS Alert protocol frame from RFC 5246 Section 7.2.
class Alert
{
public:
    explicit Alert(Parser::BinaryTokenizer &tk);

    bool fatal() const { return level == 2; }

    uint8_t level; ///< warning or fatal
    uint8_t description; ///< close_notify, unexpected_message, etc.
};

/// The size of the TLS Random structure from RFC 5246 Section 7.4.1.2.
static const uint64_t HelloRandomSize = 32;

/// TLS Hello Extension from RFC 5246 Section 7.4.1.4.
class Extension
{
public:
    typedef uint16_t Type;
    explicit Extension(Parser::BinaryTokenizer &tk);

    /// whether this extension is supported by Squid and, hence, may be bumped
    /// after peeking or spliced after staring (subject to other restrictions)
    bool supported() const;

    Type type;
    SBuf data;
};

/// Extension types optimized for fast lookups.
typedef std::unordered_set<Extension::Type> Extensions;
static Extensions SupportedExtensions();

} // namespace Security

/// Convenience helper: We parse ProtocolVersion but store "int".
static AnyP::ProtocolVersion
ParseProtocolVersion(Parser::BinaryTokenizer &tk)
{
    Parser::BinaryTokenizerContext context(tk, ".version");
    uint8_t vMajor = tk.uint8(".major");
    uint8_t vMinor = tk.uint8(".minor");
    if (vMajor == 0 && vMinor == 2)
        return AnyP::ProtocolVersion(AnyP::PROTO_SSL, 2, 0);

    Must(vMajor == 3);
    if (vMinor == 0)
        return AnyP::ProtocolVersion(AnyP::PROTO_SSL, 3, 0);

    return AnyP::ProtocolVersion(AnyP::PROTO_TLS, 1, (vMinor - 1));
}

Security::TLSPlaintext::TLSPlaintext(Parser::BinaryTokenizer &tk)
{
    Parser::BinaryTokenizerContext context(tk, "TLSPlaintext");
    type = tk.uint8(".type");
    Must(type >= ctChangeCipherSpec && type <= ctApplicationData);
    version = ParseProtocolVersion(tk);
    // TODO: Must(version.major == 3);
    fragment = tk.pstring16(".fragment");
    context.success();
}

Security::Handshake::Handshake(Parser::BinaryTokenizer &tk)
{
    Parser::BinaryTokenizerContext context(tk, "Handshake");
    msg_type = tk.uint8(".msg_type");
    msg_body = tk.pstring24(".msg_body");
    context.success();
}

Security::Alert::Alert(Parser::BinaryTokenizer &tk)
{
    Parser::BinaryTokenizerContext context(tk, "Alert");
    level = tk.uint8(".level");
    description = tk.uint8(".description");
    context.success();
}

Security::Extension::Extension(Parser::BinaryTokenizer &tk)
{
    Parser::BinaryTokenizerContext context(tk, "Extension");
    type = tk.uint16(".type");
    data = tk.pstring16(".data");
    context.success();
}

bool
Security::Extension::supported() const
{
    static const Extensions supportedExtensions = SupportedExtensions();
    return supportedExtensions.find(type) != supportedExtensions.end();
}

Security::Sslv2Record::Sslv2Record(Parser::BinaryTokenizer &tk)
{
    Parser::BinaryTokenizerContext context(tk, "Sslv2Record");
    const uint16_t head = tk.uint16(".head");
    const uint16_t length = head & 0x7FFF;
    Must((head & 0x8000) && length); // SSLv2 message [without padding]
    fragment = tk.area(length, ".fragment");
    context.success();
}

Security::TlsDetails::TlsDetails():
    compressionSupported(false),
    doHeartBeats(false),
    tlsTicketsExtension(false),
    hasTlsTicket(false),
    tlsStatusRequest(false),
    unsupportedExtensions(false)
{
}

/* Security::HandshakeParser */

Security::HandshakeParser::HandshakeParser():
    details(new TlsDetails),
    state(atHelloNone),
    resumingSession(false),
    currentContentType(0),
    done(nullptr),
    expectingModernRecords(false)
{
}

void
Security::HandshakeParser::parseVersion2Record()
{
    const Sslv2Record record(tkRecords);
    tkRecords.commit();
    details->tlsVersion = AnyP::ProtocolVersion(AnyP::PROTO_SSL, 2, 0);
    parseVersion2HandshakeMessage(record.fragment);
    state = atHelloReceived;
    done = "SSLv2";
}

/// RFC 5246. Appendix E.2. Compatibility with SSL 2.0
/// And draft-hickman-netscape-ssl-00. Section 4.1. SSL Record Header Format
bool
Security::HandshakeParser::isSslv2Record(const SBuf &raw) const
{
    Parser::BinaryTokenizer tk(raw, true);
    const uint16_t head = tk.uint16("?v2Hello.msg_head");
    const uint8_t type = tk.uint8("?v2Hello.msg_type");
    const uint16_t length = head & 0x7FFF;
    return (head & 0x8000) && length && type == 1;
}

void
Security::HandshakeParser::parseRecord()
{
    if (expectingModernRecords)
        parseModernRecord();
    else
        parseVersion2Record();
}

/// parses a single TLS Record Layer frame
void
Security::HandshakeParser::parseModernRecord()
{
    const TLSPlaintext record(tkRecords);
    tkRecords.commit();

    details->tlsVersion = record.version;

    // RFC 5246: length MUST NOT exceed 2^14
    Must(record.fragment.length() <= (1 << 14));
    // RFC 5246: MUST NOT send zero-length [non-application] fragments
    Must(record.fragment.length() || record.type == ContentType::ctApplicationData);

    if (currentContentType != record.type) {
        Must(tkMessages.atEnd()); // no currentContentType leftovers
        fragments = record.fragment;
        tkMessages.reset(fragments, true); // true because more fragments may come
        currentContentType = record.type;
    } else {
        fragments.append(record.fragment);
        tkMessages.reinput(fragments, true); // true because more fragments may come
        tkMessages.rollback();
    }
    parseMessages();
