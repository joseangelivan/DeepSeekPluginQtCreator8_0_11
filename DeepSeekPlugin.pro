TARGET = DeepSeekPlugin
TEMPLATE = lib
QT += core gui network widgets

# Use C++17 for compatibility with Qt Creator 16.0.1
CONFIG += plugin c++17

# Paths to Qt Creator
IDE_SOURCE_TREE = /opt/qtcreator-16.0.1
IDE_BUILD_TREE = /opt/qtcreator-16.0.1
message( IDE_SOURCE_TREE:  $${IDE_SOURCE_TREE} )

# Add our compatibility directory first to intercept includes
INCLUDEPATH += $$PWD/compat

# Include paths
INCLUDEPATH += $${IDE_SOURCE_TREE}/include/qtcreator
INCLUDEPATH += $${IDE_SOURCE_TREE}/include/qtcreator/src
INCLUDEPATH += $${IDE_SOURCE_TREE}/include/qtcreator/src/libs
INCLUDEPATH += $${IDE_SOURCE_TREE}/include/qtcreator/src/plugins

# Library paths
LIBS += -L$$IDE_BUILD_TREE/lib/qtcreator
LIBS += -L$$IDE_BUILD_TREE/lib/qtcreator/plugins

QTC_PLUGIN_NAME = DeepSeekPlugin
QTC_LIB_DEPENDS += \
    utils

QTC_PLUGIN_DEPENDS += \
    coreplugin \
    texteditor

# Ensure we can find qtcreatorplugin.pri
!exists($$IDE_SOURCE_TREE/src/qtcreatorplugin.pri) {
    # Use the shipped pri file as fallback
    include(qtcreatorplugin.pri)
    message("Usando qtcreatorplugin.pri incluido")
} else {
    include($$IDE_SOURCE_TREE/src/qtcreatorplugin.pri)
}

# Input files
HEADERS += \
    compat/QByteArrayView.h \
    deepseekplugin.h \
    deepseekwidget.h \
    deepseekoptionspage.h \
    deepseeksettings.h \
    deepseektr.h \
    deepseekoutputpane.h

SOURCES += \
    deepseekplugin.cpp \
    deepseekwidget.cpp \
    deepseekoptionspage.cpp \
    deepseeksettings.cpp \
    deepseekoutputpane.cpp

RESOURCES += \
    resources.qrc

FORMS += \
    deepseekwidget.ui \
    deepseekoptionspage.ui

# Plugin MetaData
OTHER_FILES += \
    DeepSeekPlugin.json \
    README.md

# Translations
TRANSLATIONS += \
    translations/deepseek_es_419.ts \
    translations/deepseek_zh_CN.ts

# Make sure the destination directory for the binary exists
QMAKE_PRE_LINK += "mkdir -p $$IDE_BUILD_TREE/lib/qtcreator/plugins"
