/****************************************************************************
** Meta object code from reading C++ file 'parsy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../blarg2/parsy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parsy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Parsy_t {
    QByteArrayData data[6];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Parsy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Parsy_t qt_meta_stringdata_Parsy = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Parsy"
QT_MOC_LITERAL(1, 6, 3), // "boo"
QT_MOC_LITERAL(2, 10, 0), // ""
QT_MOC_LITERAL(3, 11, 6), // "booboo"
QT_MOC_LITERAL(4, 18, 22), // "QProcess::ProcessError"
QT_MOC_LITERAL(5, 41, 1) // "x"

    },
    "Parsy\0boo\0\0booboo\0QProcess::ProcessError\0"
    "x"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Parsy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x0a /* Public */,
       3,    1,   25,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void Parsy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Parsy *_t = static_cast<Parsy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->boo(); break;
        case 1: _t->booboo((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Parsy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Parsy.data,
      qt_meta_data_Parsy,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Parsy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Parsy::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Parsy.stringdata0))
        return static_cast<void*>(const_cast< Parsy*>(this));
    return QObject::qt_metacast(_clname);
}

int Parsy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
