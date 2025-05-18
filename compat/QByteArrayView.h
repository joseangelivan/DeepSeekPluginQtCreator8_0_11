#pragma once

#include <QtCore/QString>
#include <QtCore/QByteArray>

// This file provides compatibility for QByteArrayView in Qt 6.8
// which might not be available in older Qt versions

#if QT_VERSION < QT_VERSION_CHECK(6, 4, 0)
class QByteArrayView
{
public:
    QByteArrayView() : m_data(nullptr), m_size(0) {}
    QByteArrayView(const char *str) : m_data(str), m_size(str ? strlen(str) : 0) {}
    QByteArrayView(const QByteArray &ba) : m_data(ba.constData()), m_size(ba.size()) {}

    const char *constData() const { return m_data; }
    qsizetype size() const { return m_size; }
    bool isEmpty() const { return m_size == 0; }

    QByteArray toByteArray() const {
        return QByteArray(m_data, static_cast<int>(m_size));
    }

    operator QByteArray() const { return toByteArray(); }

private:
    const char *m_data;
    qsizetype m_size;
};
#endif
