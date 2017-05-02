/****************************************************************************
** Meta object code from reading C++ file 'bytaskpanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tabwidget2/tabWidgetFiles/Containers_Panels/bytaskpanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bytaskpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ByTaskPanel_t {
    QByteArrayData data[15];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ByTaskPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ByTaskPanel_t qt_meta_stringdata_ByTaskPanel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ByTaskPanel"
QT_MOC_LITERAL(1, 12, 9), // "taskPause"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 6), // "taskId"
QT_MOC_LITERAL(4, 30, 8), // "taskPlay"
QT_MOC_LITERAL(5, 39, 10), // "ChangeMode"
QT_MOC_LITERAL(6, 50, 9), // "PanelMode"
QT_MOC_LITERAL(7, 60, 4), // "mode"
QT_MOC_LITERAL(8, 65, 6), // "resort"
QT_MOC_LITERAL(9, 72, 10), // "ChangeName"
QT_MOC_LITERAL(10, 83, 4), // "name"
QT_MOC_LITERAL(11, 88, 12), // "ChangeLeader"
QT_MOC_LITERAL(12, 101, 6), // "leader"
QT_MOC_LITERAL(13, 108, 12), // "DecreaseMode"
QT_MOC_LITERAL(14, 121, 12) // "IncreaseMode"

    },
    "ByTaskPanel\0taskPause\0\0taskId\0taskPlay\0"
    "ChangeMode\0PanelMode\0mode\0resort\0"
    "ChangeName\0name\0ChangeLeader\0leader\0"
    "DecreaseMode\0IncreaseMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ByTaskPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   70,    2, 0x0a /* Public */,
       5,    1,   75,    2, 0x2a /* Public | MethodCloned */,
       9,    2,   78,    2, 0x0a /* Public */,
       9,    1,   83,    2, 0x2a /* Public | MethodCloned */,
      11,    2,   86,    2, 0x0a /* Public */,
      11,    1,   91,    2, 0x2a /* Public | MethodCloned */,
      13,    0,   94,    2, 0x09 /* Protected */,
      14,    0,   95,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6, QMetaType::Bool,    7,    8,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   10,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   12,    8,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ByTaskPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ByTaskPanel *_t = static_cast<ByTaskPanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->taskPause((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->taskPlay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->ChangeMode((*reinterpret_cast< PanelMode(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->ChangeMode((*reinterpret_cast< PanelMode(*)>(_a[1]))); break;
        case 4: _t->ChangeName((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 5: _t->ChangeName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->ChangeLeader((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->ChangeLeader((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->DecreaseMode(); break;
        case 9: _t->IncreaseMode(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ByTaskPanel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ByTaskPanel::taskPause)) {
                *result = 0;
            }
        }
        {
            typedef void (ByTaskPanel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ByTaskPanel::taskPlay)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ByTaskPanel::staticMetaObject = {
    { &QSidePanel::staticMetaObject, qt_meta_stringdata_ByTaskPanel.data,
      qt_meta_data_ByTaskPanel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ByTaskPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ByTaskPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ByTaskPanel.stringdata0))
        return static_cast<void*>(const_cast< ByTaskPanel*>(this));
    return QSidePanel::qt_metacast(_clname);
}

int ByTaskPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSidePanel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ByTaskPanel::taskPause(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ByTaskPanel::taskPlay(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
