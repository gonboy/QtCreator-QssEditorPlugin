#ifndef QSSEDITORPLUGIN_H
#define QSSEDITORPLUGIN_H

#include "qsseditor_global.h"

#include <extensionsystem/iplugin.h>

namespace QssEditor {
namespace Internal {

class QSSEDITORSHARED_EXPORT QssEditorPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "QssEditorPlugin.json")

public:
    QssEditorPlugin();
    ~QssEditorPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private slots:
    void triggerAction();
};

} // namespace Internal
} // namespace QssEditor

#endif // QSSEDITORPLUGIN_H

