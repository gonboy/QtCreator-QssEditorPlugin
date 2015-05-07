#include "qsseditorplugin.h"

#include "qsseditorconstants.h"

#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/editormanager/editormanager.h>
#include <coreplugin/editormanager/ieditor.h>
#include <coreplugin/coreconstants.h>
#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/fileiconprovider.h>

#include <utils/mimetypes/mimedatabase.h>

#include <QAction>
#include <QApplication>
#include <QMessageBox>
#include <QMenu>
#include <QShortcut>

#include <QtPlugin>

using namespace QssEditor::Internal;


//////////////////////////// QssEditorPlugin /////////////////////////////

QssEditorPlugin::QssEditorPlugin()
{
    // Create your members
}

QssEditorPlugin::~QssEditorPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool QssEditorPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    Q_UNUSED(arguments);
    Q_UNUSED(errorString);

    Utils::MimeDatabase::addMimeTypes(QLatin1String(":/qsseditor/QssEditor.mimetypes.xml"));

    QAction *action = new QAction(tr("QssEditorPlugin action"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                                             Core::Context(Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+A")));
    connect(action, SIGNAL(triggered()), this, SLOT(triggerAction()));

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("QssEditorPlugin"));
    menu->addAction(cmd);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    return true;
}

void QssEditorPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag QssEditorPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

void QssEditorPlugin::triggerAction()
{
    QMessageBox::information(Core::ICore::mainWindow(),
                             tr("Action triggered"),
                             tr("This is an action from QssEditor Plugin."));
}
