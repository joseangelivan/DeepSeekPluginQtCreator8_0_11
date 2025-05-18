#include "deepseektr.h"

#include <QCoreApplication>

namespace DeepSeek {
namespace Internal {

QString Tr::tr(const char *sourceText)
{
    return QCoreApplication::translate("DeepSeek", sourceText);
}

} // namespace Internal
} // namespace DeepSeek
