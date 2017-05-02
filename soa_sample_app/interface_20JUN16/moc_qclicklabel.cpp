/****************************************************************************
** Meta object code from reading C++ file 'qclicklabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tabwidget2/tabWidgetFiles/qclicklabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qclicklabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QClickLabel_t {
    QByteArrayData data[6];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QClickLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QClickLabel_t qt_meta_stringdata_QClickLabel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QClickLabel"
QT_MOC_LITERAL(1, 12, 7), // "Clicked"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "Pressed"
QT_MOC_LITERAL(4, 29, 8), // "Released"
QT_MOC_LITERAL(5, 38, 13) // "DoubleClicked"

    },
    "QClickLabel\0Clicked\0\0Pressed\0Released\0"
    "DoubleClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QClickLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    0,   36,    2, 0x06 /* Public */,
       5,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QClickLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QClickLabel *_t = static_cast<QClickLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Clicked(); break;
        case 1: _t->Pressed(); break;
        case 2: _t->Released(); break;
        case 3: _t->DoubleClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QClickLabel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QClickLabel::Clicked)) {
                *result = 0;
            }
        }
        {
            typedef void (QClickLabel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QClickLabel::Pressed)) {
                *result = 1;
            }
        }
        {
            typedef void (QClickLabel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QClickLabel::Released)) {
                *result = 2;
            }
        }
        {
            typedef void (QClickLabel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QClickLabel::DoubleClicked)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject QClickLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_QClickLabel.data,
      qt_meta_data_QClickLabel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QClickLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QClickLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QClickLabel.stringdata0))
        return static_cast<void*>(const_cast< QClickLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int QClickLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QClickLabel::Clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void QClickLabel::Pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void QClickLabel::Released()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void QClickLabel::DoubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
