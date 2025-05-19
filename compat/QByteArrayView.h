#pragma once

#include <QtCore/QString>
#include <QtCore/QByteArray>
#include <QtCore/QtGlobal> // For QT_VERSION_CHECK

// This file provides compatibility for QByteArrayView in Qt 6.8
// which might not be available in older Qt versions

#if (QT_VERSION < QT_VERSION_CHECK(6, 4, 0))
class QByteArrayView
{
public:
    // Constructors
    QByteArrayView() noexcept : m_data(nullptr), m_size(0) {}

    // Constructor from C-string (null-terminated)
    QByteArrayView(const char *str) noexcept
        : m_data(str), m_size(str ? strlen(str) : 0) {}

    // Constructor from QByteArray
    QByteArrayView(const QByteArray &ba) noexcept
        : m_data(ba.constData()), m_size(ba.size()) {}

    // Constructor from data and size
    QByteArrayView(const char *data, qsizetype size) noexcept
        : m_data(data), m_size(size) {}

    // Data access
    const char *constData() const noexcept { return m_data; }
    const char *data() const noexcept { return m_data; }
    qsizetype size() const noexcept { return m_size; }
    bool isEmpty() const noexcept { return m_size == 0; }
    bool isNull() const noexcept { return m_data == nullptr; }

    // Conversion methods
    QByteArray toByteArray() const {
        return QByteArray(m_data, static_cast<int>(m_size));
    }

    // Conversion operator
    operator QByteArray() const { return toByteArray(); }

    // String conversion
    QString toString() const {
        return QString::fromUtf8(m_data, static_cast<int>(m_size));
    }

    // Equality operators
    bool operator==(const QByteArrayView &other) const {
        if (m_size != other.m_size)
            return false;
        return m_size == 0 || memcmp(m_data, other.m_data, size_t(m_size)) == 0;
    }

    bool operator!=(const QByteArrayView &other) const {
        return !(*this == other);
    }

private:
    const char *m_data;
    qsizetype m_size;
};
#endif // QT_VERSION check
