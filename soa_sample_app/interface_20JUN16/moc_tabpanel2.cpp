/****************************************************************************
** Meta object code from reading C++ file 'tabpanel2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tabwidget2/tabpanel2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabpanel2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TabPanel2_t {
    QByteArrayData data[20];
    char stringdata0[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TabPanel2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TabPanel2_t qt_meta_stringdata_TabPanel2 = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TabPanel2"
QT_MOC_LITERAL(1, 10, 12), // "centerOnTask"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 3), // "pId"
QT_MOC_LITERAL(4, 28, 10), // "taskActive"
QT_MOC_LITERAL(5, 39, 2), // "Id"
QT_MOC_LITERAL(6, 42, 8), // "editTask"
QT_MOC_LITERAL(7, 51, 15), // "CenterMapOnTask"
QT_MOC_LITERAL(8, 67, 11), // "RemovePanel"
QT_MOC_LITERAL(9, 79, 8), // "QAction*"
QT_MOC_LITERAL(10, 88, 7), // "pAction"
QT_MOC_LITERAL(11, 96, 35), // "SidePanelContextMenuActionTri..."
QT_MOC_LITERAL(12, 132, 7), // "addTask"
QT_MOC_LITERAL(13, 140, 9), // "taskInfo*"
QT_MOC_LITERAL(14, 150, 5), // "ttask"
QT_MOC_LITERAL(15, 156, 12), // "taskSelected"
QT_MOC_LITERAL(16, 169, 11), // "QSidePanel*"
QT_MOC_LITERAL(17, 181, 8), // "taskEdit"
QT_MOC_LITERAL(18, 190, 7), // "endTask"
QT_MOC_LITERAL(19, 198, 2) // "id"

    },
    "TabPanel2\0centerOnTask\0\0pId\0taskActive\0"
    "Id\0editTask\0CenterMapOnTask\0RemovePanel\0"
    "QAction*\0pAction\0SidePanelContextMenuActionTriggered\0"
    "addTask\0taskInfo*\0ttask\0taskSelected\0"
    "QSidePanel*\0taskEdit\0endTask\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TabPanel2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   73,    2, 0x0a /* Public */,
       8,    1,   76,    2, 0x0a /* Public */,
      11,    1,   79,    2, 0x0a /* Public */,
      12,    1,   82,    2, 0x0a /* Public */,
      15,    1,   85,    2, 0x0a /* Public */,
      17,    1,   88,    2, 0x0a /* Public */,
      18,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::VoidStar,    3,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, QMetaType::Int,   19,

       0        // eod
};

void TabPanel2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TabPanel2 *_t = static_cast<TabPanel2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->centerOnTask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->taskActive((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->editTask((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->CenterMapOnTask((*reinterpret_cast< void*(*)>(_a[1]))); break;
        case 4: _t->RemovePanel((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 5: _t->SidePanelContextMenuActionTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 6: _t->addTask((*reinterpret_cast< taskInfo*(*)>(_a[1]))); break;
        case 7: _t->taskSelected((*reinterpret_cast< QSidePanel*(*)>(_a[1]))); break;
        case 8: _t->taskEdit((*reinterpret_cast< QSidePanel*(*)>(_a[1]))); break;
        case 9: _t->endTask((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TabPanel2::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabPanel2::centerOnTask)) {
                *result = 0;
            }
        }
        {
            typedef void (TabPanel2::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabPanel2::taskActive)) {
                *result = 1;
            }
        }
        {
            typedef void (TabPanel2::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TabPanel2::editTask)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject TabPanel2::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TabPanel2.data,
      qt_meta_data_TabPanel2,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TabPanel2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TabPanel2::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TabPanel2.stringdata0))
        return static_cast<void*>(const_cast< TabPanel2*>(this));
    return QWidget::qt_metacast(_clname);
}

int TabPanel2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void TabPanel2::centerOnTask(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TabPanel2::taskActive(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TabPanel2::editTask(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
