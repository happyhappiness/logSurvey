};

/// TLS Handshake Protocol frame from RFC 5246 Section 7.4.
struct Handshake: public FieldGroup
{
    explicit Handshake(BinaryTokenizer &tk);

    uint32_t msg_type: 8; ///< HandshakeType
    uint32_t length: 24;
    SBuf body; ///< Handshake Protocol message, exactly length bytes
};

/// TLS Alert protocol frame from RFC 5246 Section 7.2.
struct Alert: public FieldGroup
{
    explicit Alert(BinaryTokenizer &tk);
    uint8_t level; ///< warning or fatal
    uint8_t description; ///< close_notify, unexpected_message, etc.
};

struct Extension: public FieldGroup
{
    explicit Extension(BinaryTokenizer &tk);
    uint16_t type;
    uint16_t length;
    SBuf body;
};

