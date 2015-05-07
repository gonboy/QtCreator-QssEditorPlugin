#ifndef QSSEDITOR_GLOBAL_H
#define QSSEDITOR_GLOBAL_H

#include <QtGlobal>

#if defined(QSSEDITOR_LIBRARY)
#  define QSSEDITORSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QSSEDITORSHARED_EXPORT Q_DECL_IMPORT
#endif

namespace QssEditor
{

enum QuickEditableType
{
    Color,
    Gradient,
    Border,
    BorderStyle
};

} // namespace QssEditor

#endif // QSSEDITOR_GLOBAL_H

