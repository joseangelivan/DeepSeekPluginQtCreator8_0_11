#pragma once

// Compatibility utilities for Qt Creator 16.0.1

#include <QtCore/QtGlobal>
#include <QtCore/QMetaType>

// Helper macros for compatibility across different Qt Creator versions
#ifndef QTC_CHECK
#define QTC_CHECK(condition) ((!(condition)) ? qWarning("ASSERT: " #condition) : qt_noop())
#endif

#ifndef QTC_ASSERT
#define QTC_ASSERT(condition, action) do { \
    if (Q_UNLIKELY(!(condition))) { \
        qWarning("ASSERTION FAILED: \"%s\" in %s at %s:%d", #condition, __FUNCTION__, __FILE__, __LINE__); \
        action; \
    } \
} while (0)
#endif

// Compatibility template to handle Q_DECLARE_METATYPE changes
// Use this when you're not sure if a type is already registered
template <typename T>
inline void registerMetaTypeIfNeeded()
{
    if (!QMetaTypeId<T>::isDefined())
        qRegisterMetaType<T>();
}

// Compatibility function for plugin extensions
namespace DeepSeek {
namespace Internal {
namespace Compat {

// Fallback function for cases where extensionsystem utils don't work
template <class T>
T *findObject() 
{
    return ExtensionSystem::PluginManager::getObject<T>();
}

} // namespace Compat
} // namespace Internal
} // namespace DeepSeek
