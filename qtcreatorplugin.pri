# Updated qtcreatorplugin.pri file for Qt Creator 16.0.1
# Based on standard Qt Creator plugin template

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
# message(QTC_PLUGIN_NAME: $$QTC_PLUGIN_NAME )

PLUGINSPEC = $${_PRO_FILE_PWD_}/$${QTC_PLUGIN_NAME}.json

# Force c++17
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

# DESTDIR = $$IDE_BUILD_TREE/lib/qtcreator/plugins

# Set destination for plugin lib
contains(QT_CONFIG, reduce_exports):CONFIG += hide_symbols

win32 {
    DLLDESTDIR = $$IDE_BUILD_TREE/bin
    LIBRARY_NAME = $$TARGET.dll
    LIBRARY_PATH = $$DLLDESTDIR/$$LIBRARY_NAME
} else {
    LIBRARY_NAME = lib$${TARGET}.so
    macx:LIBRARY_NAME = lib$${TARGET}.dylib
    LIBRARY_PATH = $$DESTDIR/$$LIBRARY_NAME
    QMAKE_LFLAGS += "-Wl,-rpath,\'$$DESTDIR\'"
}

qtcinstall.files = $$DESTDIR/$$LIBRARY_NAME
!isEmpty(USE_USER_DESTDIR) {
    qtcinstall.path = $${USE_USER_DESTDIR}/lib/qtcreator/plugins
    INSTALLS += qtcinstall
}

unix:!macx {
    # Create symbolic links for the plugin
    QMAKE_POST_LINK += "ln -f -s lib$${TARGET}.so lib$${TARGET}.so.1 && "
    QMAKE_POST_LINK += "ln -f -s lib$${TARGET}.so.1 lib$${TARGET}.so.1.0 && "
    QMAKE_POST_LINK += "ln -f -s lib$${TARGET}.so.1.0 lib$${TARGET}.so.1.0.0"
}

LIBS += -L$$IDE_BUILD_TREE/lib/qtcreator
LIBS += -L$$IDE_BUILD_TREE/lib/qtcreator/plugins

# plugin dependencies
defineReplace(dependencyName) {
    dependency_name = $$1
    CONFIG(debug, debug|release) {
        !debug_and_release|build_pass {
            win32:dependency_name = $${dependency_name}d
        }
    }
    return($$dependency_name)
}

# Configurar el nombre y dependencias del plugin
# QTC_PLUGIN_NAME = DeepSeekPlugin
# QTC_PLUGIN_DEPENDS = coreplugin texteditor

# Definir una función para mapear los nombres internos a nombres de biblioteca
defineReplace(mapPluginNameToLib) {
    pluginName = $$1
    equals(pluginName, "coreplugin"):return(Core)
    equals(pluginName, "texteditor"):return(TextEditor)
    return($$pluginName)  # Devolver sin cambios para otros casos
}

# defineReplace(libToLink) {
#     # Convierte el nombre de la librería (ej. utils) en -lUtils
#     libname = $$1
#     first_char = $$upper($$left($$libname, 1))
#     rest_chars = $$right($$libname, -1)
#     return(-l$$first_char$$rest_chars)
# }


# message(QTC_LIB_DEPENDS: $$QTC_LIB_DEPENDS)
# # for lib dependencies
# for(dep, QTC_LIB_DEPENDS) {
#     message(libs: $$dep)
#     LIBS += -l$$upper(${QTC_LIB_DEPENDS})
# }
LIBS += -lUtils

message(QTC_LIB_DEPENDS: $$QTC_LIB_DEPENDS)

# Convertir manualmente las dependencias conocidas
for(dep, QTC_LIB_DEPENDS) {
    # contains(dep, utils) {
    #     LIBS += -lUtils
    # }
    # Añade más condiciones para otras librerías si es necesario
    # else {
        # LIBS += -l$$dep
    # }
}

message(Resulting LIBS: $$LIBS)


message(QTC_PLUGIN_DEPENDS: $$QTC_PLUGIN_DEPENDS)
for(dep, QTC_PLUGIN_DEPENDS) {
    LIBS += -l$$mapPluginNameToLib($$dep)
}




# LIBS += -lCore -lTextEditor

# Additional directories to look for libraries
LIBS += -L$${IDE_BUILD_TREE}/lib/qtcreator
LIBS += -L$${IDE_BUILD_TREE}/lib/qtcreator/plugins
