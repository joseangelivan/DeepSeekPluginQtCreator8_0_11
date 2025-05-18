# Backup qtcreatorplugin.pri file in case the original one is not found
# Based on standard Qt Creator plugin template for Qt 5.14.2

DEFINES += DEEPSEEKPLUGIN_LIBRARY
# Qt Creator linking

## Either set the IDE_SOURCE_TREE when running qmake,
## or set the QTC_SOURCE environment variable, to override the default setting
isEmpty(IDE_SOURCE_TREE): IDE_SOURCE_TREE = $$(QTC_SOURCE)
isEmpty(IDE_SOURCE_TREE): IDE_SOURCE_TREE = /opt/qtcreator-16.0.1

## Either set the IDE_BUILD_TREE when running qmake,
## or set the QTC_BUILD environment variable, to override the default setting
isEmpty(IDE_BUILD_TREE): IDE_BUILD_TREE = $$(QTC_BUILD)
isEmpty(IDE_BUILD_TREE): IDE_BUILD_TREE = /opt/qtcreator-16.0.1

## Plugin dependencies and 'pluginspec'
isEmpty(QTC_PLUGIN_NAME):error("QTC_PLUGIN_NAME must be set, for example to 'MyPlugin'.")

PLUGINSPEC = $${_PRO_FILE_PWD_}/$${QTC_PLUGIN_NAME}.json

# Force c++14
# CONFIG += c++14
CONFIG += c++17
message(QTC_PLUGIN_DIRS: $$(QTC_PLUGIN_DIRS))
# Qt Creator from environment
QTC_PLUGIN_DIRS = $$(QTC_PLUGIN_DIRS)
QTC_PLUGIN_DIRS = $$split(QTC_PLUGIN_DIRS, :)
QTC_PLUGIN_DIRS += $$IDE_SOURCE_TREE/src/plugins
QTC_PLUGIN_DIRS += $$IDE_BUILD_TREE/src/plugins
for(dir, QTC_PLUGIN_DIRS) {
    INCLUDEPATH *= $${dir}
}

# Add absolute path to plugin in qtcinstall.path if qtcinstall.path is set by user
isEmpty(USE_USER_DESTDIR) {
    isEmpty(qtcinstall.path):qtcinstall.path = $$(QTC_INSTALL)
    !isEmpty(qtcinstall.path):USE_USER_DESTDIR = $$qtcinstall.path
}

DESTDIR = $$IDE_BUILD_TREE/lib/qtcreator/plugins

# Set destination for plugin lib
qtcinstall.files = $$DESTDIR/$$qtLibraryTargetName($$TARGET)
!isEmpty(USE_USER_DESTDIR) {
    qtcinstall.path = $${USE_USER_DESTDIR}/lib/qtcreator/plugins
    INSTALLS += qtcinstall
}

unix:!macx {
    # for a change in lib name from "lib$${TARGET}.so.1.0.0" to "lib$${TARGET}.so"
    QMAKE_POST_LINK += $$sprintf($$QMAKE_SYMBOLIC_LINK, $$qtLibraryTargetName($$TARGET), lib$${TARGET}.so)
    QMAKE_POST_LINK += $$sprintf($$QMAKE_SYMBOLIC_LINK, lib$${TARGET}.so, lib$${TARGET}.so.1)
    QMAKE_POST_LINK += $$sprintf($$QMAKE_SYMBOLIC_LINK, lib$${TARGET}.so.1, lib$${TARGET}.so.1.0)
    QMAKE_POST_LINK += $$sprintf($$QMAKE_SYMBOLIC_LINK, lib$${TARGET}.so.1.0, lib$${TARGET}.so.1.0.0)
}

LIBS += -L$$IDE_BUILD_TREE/lib/qtcreator
LIBS += -L$$IDE_BUILD_TREE/lib/qtcreator/plugins

# plugin dependencies
for(dep, QTC_PLUGIN_DEPENDS) {
    # copy the list as qtLibraryName() modifies the original content
    LIBS += -l$$qtLibraryName($$dep)
}

# for lib dependencies
for(dep, QTC_LIB_DEPENDS) {
    LIBS += -l$$qtLibraryName($$dep)
}
