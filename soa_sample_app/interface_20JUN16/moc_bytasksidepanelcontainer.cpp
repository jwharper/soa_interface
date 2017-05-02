/****************************************************************************
** Meta object code from reading C++ file 'bytasksidepanelcontainer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tabwidget2/tabWidgetFiles/Containers_Panels/bytasksidepanelcontainer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bytasksidepanelcontainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ByTaskSidePanelContainer_t {
    QByteArrayData data[4];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ByTaskSidePanelContainer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ByTaskSidePanelContainer_t qt_meta_stringdata_ByTaskSidePanelContainer = {
    {
QT_MOC_LITERAL(0, 0, 24), // "ByTaskSidePanelContainer"
QT_MOC_LITERAL(1, 25, 10), // "SortPanels"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 6) // "method"

    },
    "ByTaskSidePanelContainer\0SortPanels\0"
    "\0method"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ByTaskSidePanelContainer[] = {

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
       1,    1,   24,    2, 0x0a /* Public */,
       1,    0,   27,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void ByTaskSidePanelContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ByTaskSidePanelContainer *_t = static_cast<ByTaskSidePanelContainer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SortPanels((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->SortPanels(); break;
        default: ;
        }
    }
}

const QMetaObject ByTaskSidePanelContainer::staticMetaObject = {
    { &QSidePanelContainer::staticMetaObject, qt_meta_stringdata_ByTaskSidePanelContainer.data,
      qt_meta_data_ByTaskSidePanelContainer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ByTaskSidePanelContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ByTaskSidePanelContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ByTaskSidePanelContainer.stringdata0))
        return static_cast<void*>(const_cast< ByTaskSidePanelContainer*>(this));
    return QSidePanelContainer::qt_metacast(_clname);
}

int ByTaskSidePanelContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSidePanelContainer::qt_metacall(_c, _id, _a);
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
