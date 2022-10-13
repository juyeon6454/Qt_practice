/****************************************************************************
** Meta object code from reading C++ file 'memoalbum.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ImageView/memoalbum.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'memoalbum.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MemoAlbum_t {
    uint offsetsAndSizes[14];
    char stringdata0[10];
    char stringdata1[6];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[11];
    char stringdata5[17];
    char stringdata6[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MemoAlbum_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_MemoAlbum_t qt_meta_stringdata_MemoAlbum = {
    {
        QT_MOC_LITERAL(0, 9),  // "MemoAlbum"
        QT_MOC_LITERAL(10, 5),  // "reset"
        QT_MOC_LITERAL(16, 0),  // ""
        QT_MOC_LITERAL(17, 12),  // "reloadImages"
        QT_MOC_LITERAL(30, 10),  // "selectItem"
        QT_MOC_LITERAL(41, 16),  // "QListWidgetItem*"
        QT_MOC_LITERAL(58, 8)   // "setImage"
    },
    "MemoAlbum",
    "reset",
    "",
    "reloadImages",
    "selectItem",
    "QListWidgetItem*",
    "setImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MemoAlbum[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x0a,    1 /* Public */,
       3,    0,   39,    2, 0x0a,    2 /* Public */,
       4,    1,   40,    2, 0x0a,    3 /* Public */,
       6,    1,   43,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void MemoAlbum::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MemoAlbum *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->reset(); break;
        case 1: _t->reloadImages(); break;
        case 2: _t->selectItem((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 3: _t->setImage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MemoAlbum::staticMetaObject = { {
    QMetaObject::SuperData::link<QSplitter::staticMetaObject>(),
    qt_meta_stringdata_MemoAlbum.offsetsAndSizes,
    qt_meta_data_MemoAlbum,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MemoAlbum_t
, QtPrivate::TypeAndForceComplete<MemoAlbum, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *MemoAlbum::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MemoAlbum::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MemoAlbum.stringdata0))
        return static_cast<void*>(this);
    return QSplitter::qt_metacast(_clname);
}

int MemoAlbum::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSplitter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
