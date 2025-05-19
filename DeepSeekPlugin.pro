TARGET = DeepSeekPlugin
TEMPLATE = lib
QT += core gui network widgets

# Use C++17 for compatibility with Qt Creator 16.0.1
CONFIG += plugin c++17

# Define plugin name
QTC_PLUGIN_NAME = DeepSeekPlugin

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
INCLUDEPATH += $${IDE_SOURCE_TREE}/include

# Library dependencies
QTC_LIB_DEPENDS += \
    utils

QTC_PLUGIN_DEPENDS += \
    coreplugin \
    texteditor

# Disable moc warnings - helps with Qt version differences
CONFIG += no_moc_predefs

# Ensure proper RPATH settings
unix:!macx:QMAKE_LFLAGS += -Wl,-rpath,\'$$IDE_BUILD_TREE/lib/qtcreator\'

# Try to load qtcreatorplugin.pri first, fall back to our own version if not found
!exists($$IDE_SOURCE_TREE/src/qtcreatorplugin.pri) {
    message("Using bundled qtcreatorplugin.pri")
    include(qtcreatorplugin.pri)
} else {
    message("Using system qtcreatorplugin.pri")
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
QMAKE_PRE_LINK += mkdir -p $$IDE_BUILD_TREE/lib/qtcreator/plugins

# Add defines to help with version compatibility
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x050F00
DEFINES += QT_DEPRECATED_WARNINGS_SINCE=0x060000
