/****************************************************************************
** Meta object code from reading C++ file 'deepseekplugin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "deepseekplugin.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>

#include <QtCore/qtmochelpers.h>

#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deepseekplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDeepSeekSCOPEInternalSCOPEDeepSeekPluginENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDeepSeekSCOPEInternalSCOPEDeepSeekPluginENDCLASS = QtMocHelpers::stringData(
    "DeepSeek::Internal::DeepSeekPlugin"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDeepSeekSCOPEInternalSCOPEDeepSeekPluginENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject DeepSeek::Internal::DeepSeekPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<ExtensionSystem::IPlugin::staticMetaObject>(),
    qt_meta_stringdata_CLASSDeepSeekSCOPEInternalSCOPEDeepSeekPluginENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDeepSeekSCOPEInternalSCOPEDeepSeekPluginENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDeepSeekSCOPEInternalSCOPEDeepSeekPluginENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DeepSeekPlugin, std::true_type>
    >,
    nullptr
} };

void DeepSeek::Internal::DeepSeekPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *DeepSeek::Internal::DeepSeekPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeepSeek::Internal::DeepSeekPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDeepSeekSCOPEInternalSCOPEDeepSeekPluginENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return ExtensionSystem::IPlugin::qt_metacast(_clname);
}

int DeepSeek::Internal::DeepSeekPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ExtensionSystem::IPlugin::qt_metacall(_c, _id, _a);
    return _id;
}
using namespace DeepSeek;
using namespace DeepSeek::Internal;

#ifdef QT_MOC_EXPORT_PLUGIN_V2
static constexpr unsigned char qt_pluginMetaDataV2_DeepSeekPlugin[] = {
    0xbf, 
    // "IID"
    0x02,  0x78,  0x21,  'o',  'r',  'g',  '.',  'q', 
    't',  '-',  'p',  'r',  'o',  'j',  'e',  'c', 
    't',  '.',  'Q',  't',  '.',  'Q',  't',  'C', 
    'r',  'e',  'a',  't',  'o',  'r',  'P',  'l', 
    'u',  'g',  'i',  'n', 
    // "className"
    0x03,  0x6e,  'D',  'e',  'e',  'p',  'S',  'e', 
    'e',  'k',  'P',  'l',  'u',  'g',  'i',  'n', 
    // "MetaData"
    0x04,  0xab,  0x68,  'C',  'a',  't',  'e',  'g', 
    'o',  'r',  'y',  0x69,  'U',  't',  'i',  'l', 
    'i',  't',  'i',  'e',  's',  0x6d,  'C',  'o', 
    'm',  'p',  'a',  't',  'V',  'e',  'r',  's', 
    'i',  'o',  'n',  0x65,  '0',  '.',  '1',  '.', 
    '0',  0x69,  'C',  'o',  'p',  'y',  'r',  'i', 
    'g',  'h',  't',  0x74,  '(',  'C',  ')',  ' ', 
    '2',  '0',  '2',  '5',  ' ',  'Y',  'o',  'u', 
    'r',  'C',  'o',  'm',  'p',  'a',  'n',  'y', 
    0x6c,  'D',  'e',  'p',  'e',  'n',  'd',  'e', 
    'n',  'c',  'i',  'e',  's',  0x82,  0xa2,  0x64, 
    'N',  'a',  'm',  'e',  0x64,  'C',  'o',  'r', 
    'e',  0x67,  'V',  'e',  'r',  's',  'i',  'o', 
    'n',  0x65,  '8',  '.',  '0',  '.',  '1',  0xa2, 
    0x64,  'N',  'a',  'm',  'e',  0x6a,  'T',  'e', 
    'x',  't',  'E',  'd',  'i',  't',  'o',  'r', 
    0x67,  'V',  'e',  'r',  's',  'i',  'o',  'n', 
    0x65,  '8',  '.',  '0',  '.',  '1',  0x6b,  'D', 
    'e',  's',  'c',  'r',  'i',  'p',  't',  'i', 
    'o',  'n',  0x78,  0x26,  'I',  'n',  't',  'e', 
    'g',  'r',  'a',  't',  'e',  's',  ' ',  'D', 
    'e',  'e',  'p',  'S',  'e',  'e',  'k',  ' ', 
    'A',  'I',  ' ',  'i',  'n',  't',  'o',  ' ', 
    'Q',  't',  ' ',  'C',  'r',  'e',  'a',  't', 
    'o',  'r',  0x6c,  'E',  'x',  'p',  'e',  'r', 
    'i',  'm',  'e',  'n',  't',  'a',  'l',  0xf5, 
    0x67,  'L',  'i',  'c',  'e',  'n',  's',  'e', 
    0x63,  'M',  'I',  'T',  0x64,  'N',  'a',  'm', 
    'e',  0x6e,  'D',  'e',  'e',  'p',  'S',  'e', 
    'e',  'k',  'P',  'l',  'u',  'g',  'i',  'n', 
    0x63,  'U',  'r',  'l',  0x77,  'h',  't',  't', 
    'p',  's',  ':',  '/',  '/',  'y',  'o',  'u', 
    'r',  'w',  'e',  'b',  's',  'i',  't',  'e', 
    '.',  'c',  'o',  'm',  0x66,  'V',  'e',  'n', 
    'd',  'o',  'r',  0x6b,  'Y',  'o',  'u',  'r', 
    'C',  'o',  'm',  'p',  'a',  'n',  'y',  0x67, 
    'V',  'e',  'r',  's',  'i',  'o',  'n',  0x65, 
    '0',  '.',  '1',  '.',  '0', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN_V2(DeepSeek::Internal::DeepSeekPlugin, DeepSeekPlugin, qt_pluginMetaDataV2_DeepSeekPlugin)
#else
QT_PLUGIN_METADATA_SECTION
Q_CONSTINIT static constexpr unsigned char qt_pluginMetaData_DeepSeekPlugin[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x21,  'o',  'r',  'g',  '.',  'q', 
    't',  '-',  'p',  'r',  'o',  'j',  'e',  'c', 
    't',  '.',  'Q',  't',  '.',  'Q',  't',  'C', 
    'r',  'e',  'a',  't',  'o',  'r',  'P',  'l', 
    'u',  'g',  'i',  'n', 
    // "className"
    0x03,  0x6e,  'D',  'e',  'e',  'p',  'S',  'e', 
    'e',  'k',  'P',  'l',  'u',  'g',  'i',  'n', 
    // "MetaData"
    0x04,  0xab,  0x68,  'C',  'a',  't',  'e',  'g', 
    'o',  'r',  'y',  0x69,  'U',  't',  'i',  'l', 
    'i',  't',  'i',  'e',  's',  0x6d,  'C',  'o', 
    'm',  'p',  'a',  't',  'V',  'e',  'r',  's', 
    'i',  'o',  'n',  0x65,  '0',  '.',  '1',  '.', 
    '0',  0x69,  'C',  'o',  'p',  'y',  'r',  'i', 
    'g',  'h',  't',  0x74,  '(',  'C',  ')',  ' ', 
    '2',  '0',  '2',  '5',  ' ',  'Y',  'o',  'u', 
    'r',  'C',  'o',  'm',  'p',  'a',  'n',  'y', 
    0x6c,  'D',  'e',  'p',  'e',  'n',  'd',  'e', 
    'n',  'c',  'i',  'e',  's',  0x82,  0xa2,  0x64, 
    'N',  'a',  'm',  'e',  0x64,  'C',  'o',  'r', 
    'e',  0x67,  'V',  'e',  'r',  's',  'i',  'o', 
    'n',  0x65,  '8',  '.',  '0',  '.',  '1',  0xa2, 
    0x64,  'N',  'a',  'm',  'e',  0x6a,  'T',  'e', 
    'x',  't',  'E',  'd',  'i',  't',  'o',  'r', 
    0x67,  'V',  'e',  'r',  's',  'i',  'o',  'n', 
    0x65,  '8',  '.',  '0',  '.',  '1',  0x6b,  'D', 
    'e',  's',  'c',  'r',  'i',  'p',  't',  'i', 
    'o',  'n',  0x78,  0x26,  'I',  'n',  't',  'e', 
    'g',  'r',  'a',  't',  'e',  's',  ' ',  'D', 
    'e',  'e',  'p',  'S',  'e',  'e',  'k',  ' ', 
    'A',  'I',  ' ',  'i',  'n',  't',  'o',  ' ', 
    'Q',  't',  ' ',  'C',  'r',  'e',  'a',  't', 
    'o',  'r',  0x6c,  'E',  'x',  'p',  'e',  'r', 
    'i',  'm',  'e',  'n',  't',  'a',  'l',  0xf5, 
    0x67,  'L',  'i',  'c',  'e',  'n',  's',  'e', 
    0x63,  'M',  'I',  'T',  0x64,  'N',  'a',  'm', 
    'e',  0x6e,  'D',  'e',  'e',  'p',  'S',  'e', 
    'e',  'k',  'P',  'l',  'u',  'g',  'i',  'n', 
    0x63,  'U',  'r',  'l',  0x77,  'h',  't',  't', 
    'p',  's',  ':',  '/',  '/',  'y',  'o',  'u', 
    'r',  'w',  'e',  'b',  's',  'i',  't',  'e', 
    '.',  'c',  'o',  'm',  0x66,  'V',  'e',  'n', 
    'd',  'o',  'r',  0x6b,  'Y',  'o',  'u',  'r', 
    'C',  'o',  'm',  'p',  'a',  'n',  'y',  0x67, 
    'V',  'e',  'r',  's',  'i',  'o',  'n',  0x65, 
    '0',  '.',  '1',  '.',  '0', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(DeepSeek::Internal::DeepSeekPlugin, DeepSeekPlugin)
#endif  // QT_MOC_EXPORT_PLUGIN_V2

QT_WARNING_POP
