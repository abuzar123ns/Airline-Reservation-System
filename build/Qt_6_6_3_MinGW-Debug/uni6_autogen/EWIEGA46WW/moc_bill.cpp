/****************************************************************************
** Meta object code from reading C++ file 'bill.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../bill.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bill.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
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
struct qt_meta_stringdata_CLASSbillENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSbillENDCLASS = QtMocHelpers::stringData(
    "bill",
    "updateBillDetails",
    "",
    "firstName",
    "lastName",
    "phoneNumber",
    "flightAvailable",
    "departureDate",
    "flyingFrom",
    "flyingTo",
    "seatNumber",
    "seatClass",
    "totalCost",
    "ticketId"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSbillENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[5];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[9];
    char stringdata5[12];
    char stringdata6[16];
    char stringdata7[14];
    char stringdata8[11];
    char stringdata9[9];
    char stringdata10[11];
    char stringdata11[10];
    char stringdata12[10];
    char stringdata13[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSbillENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSbillENDCLASS_t qt_meta_stringdata_CLASSbillENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "bill"
        QT_MOC_LITERAL(5, 17),  // "updateBillDetails"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 9),  // "firstName"
        QT_MOC_LITERAL(34, 8),  // "lastName"
        QT_MOC_LITERAL(43, 11),  // "phoneNumber"
        QT_MOC_LITERAL(55, 15),  // "flightAvailable"
        QT_MOC_LITERAL(71, 13),  // "departureDate"
        QT_MOC_LITERAL(85, 10),  // "flyingFrom"
        QT_MOC_LITERAL(96, 8),  // "flyingTo"
        QT_MOC_LITERAL(105, 10),  // "seatNumber"
        QT_MOC_LITERAL(116, 9),  // "seatClass"
        QT_MOC_LITERAL(126, 9),  // "totalCost"
        QT_MOC_LITERAL(136, 8)   // "ticketId"
    },
    "bill",
    "updateBillDetails",
    "",
    "firstName",
    "lastName",
    "phoneNumber",
    "flightAvailable",
    "departureDate",
    "flyingFrom",
    "flyingTo",
    "seatNumber",
    "seatClass",
    "totalCost",
    "ticketId"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSbillENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,   11,   20,    2, 0x0a,    1 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::QString,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,

       0        // eod
};

Q_CONSTINIT const QMetaObject bill::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSbillENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSbillENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSbillENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<bill, std::true_type>,
        // method 'updateBillDetails'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void bill::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<bill *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateBillDetails((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[11]))); break;
        default: ;
        }
    }
}

const QMetaObject *bill::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bill::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSbillENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int bill::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
