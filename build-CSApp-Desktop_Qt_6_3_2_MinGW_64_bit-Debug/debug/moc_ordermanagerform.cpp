/****************************************************************************
** Meta object code from reading C++ file 'ordermanagerform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../CSApp/CSApp/ordermanagerform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ordermanagerform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_OrderManagerForm_t {
    uint offsetsAndSizes[24];
    char stringdata0[17];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[11];
    char stringdata5[33];
    char stringdata6[34];
    char stringdata7[38];
    char stringdata8[37];
    char stringdata9[17];
    char stringdata10[5];
    char stringdata11[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_OrderManagerForm_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_OrderManagerForm_t qt_meta_stringdata_OrderManagerForm = {
    {
        QT_MOC_LITERAL(0, 16),  // "OrderManagerForm"
        QT_MOC_LITERAL(17, 11),  // "clientAdded"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 15),  // "showContextMenu"
        QT_MOC_LITERAL(46, 10),  // "removeItem"
        QT_MOC_LITERAL(57, 32),  // "on_orderSearchPushButton_clicked"
        QT_MOC_LITERAL(90, 33),  // "on_oderInputAddPushButton_cli..."
        QT_MOC_LITERAL(124, 37),  // "on_orderInputModifyPushButton..."
        QT_MOC_LITERAL(162, 36),  // "on_orderSearchTreeWidget_item..."
        QT_MOC_LITERAL(199, 16),  // "QTreeWidgetItem*"
        QT_MOC_LITERAL(216, 4),  // "item"
        QT_MOC_LITERAL(221, 6)   // "column"
    },
    "OrderManagerForm",
    "clientAdded",
    "",
    "showContextMenu",
    "removeItem",
    "on_orderSearchPushButton_clicked",
    "on_oderInputAddPushButton_clicked",
    "on_orderInputModifyPushButton_clicked",
    "on_orderSearchTreeWidget_itemClicked",
    "QTreeWidgetItem*",
    "item",
    "column"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OrderManagerForm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   59,    2, 0x08,    3 /* Private */,
       4,    0,   62,    2, 0x08,    5 /* Private */,
       5,    0,   63,    2, 0x08,    6 /* Private */,
       6,    0,   64,    2, 0x08,    7 /* Private */,
       7,    0,   65,    2, 0x08,    8 /* Private */,
       8,    2,   66,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9, QMetaType::Int,   10,   11,

       0        // eod
};

void OrderManagerForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<OrderManagerForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clientAdded((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->showContextMenu((*reinterpret_cast< std::add_pointer_t<QPoint>>(_a[1]))); break;
        case 2: _t->removeItem(); break;
        case 3: _t->on_orderSearchPushButton_clicked(); break;
        case 4: _t->on_oderInputAddPushButton_clicked(); break;
        case 5: _t->on_orderInputModifyPushButton_clicked(); break;
        case 6: _t->on_orderSearchTreeWidget_itemClicked((*reinterpret_cast< std::add_pointer_t<QTreeWidgetItem*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (OrderManagerForm::*)(QString );
            if (_t _q_method = &OrderManagerForm::clientAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject OrderManagerForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_OrderManagerForm.offsetsAndSizes,
    qt_meta_data_OrderManagerForm,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_OrderManagerForm_t
, QtPrivate::TypeAndForceComplete<OrderManagerForm, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QPoint &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *OrderManagerForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OrderManagerForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_OrderManagerForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int OrderManagerForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void OrderManagerForm::clientAdded(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE