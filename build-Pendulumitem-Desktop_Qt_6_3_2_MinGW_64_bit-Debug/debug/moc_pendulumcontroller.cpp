/****************************************************************************
** Meta object code from reading C++ file 'pendulumcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Pendulumitem/pendulumcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pendulumcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pendulumcontroller_t {
    uint offsetsAndSizes[10];
    char stringdata0[19];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[2];
    char stringdata4[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Pendulumcontroller_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_Pendulumcontroller_t qt_meta_stringdata_Pendulumcontroller = {
    {
        QT_MOC_LITERAL(0, 18),  // "Pendulumcontroller"
        QT_MOC_LITERAL(19, 14),  // "slotRotateItem"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 1),  // "r"
        QT_MOC_LITERAL(37, 19)   // "slotRestartTimeLine"
    },
    "Pendulumcontroller",
    "slotRotateItem",
    "",
    "r",
    "slotRestartTimeLine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pendulumcontroller[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x08,    1 /* Private */,
       4,    0,   29,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void Pendulumcontroller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Pendulumcontroller *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->slotRotateItem((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->slotRestartTimeLine(); break;
        default: ;
        }
    }
}

const QMetaObject Pendulumcontroller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Pendulumcontroller.offsetsAndSizes,
    qt_meta_data_Pendulumcontroller,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Pendulumcontroller_t
, QtPrivate::TypeAndForceComplete<Pendulumcontroller, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Pendulumcontroller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pendulumcontroller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pendulumcontroller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Pendulumcontroller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
