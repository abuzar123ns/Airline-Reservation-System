/****************************************************************************
** Meta object code from reading C++ file 'bookflightwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../bookflightwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bookflightwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSbookflightwindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSbookflightwindowENDCLASS = QtMocHelpers::stringData(
    "bookflightwindow",
    "sendBookingDetails",
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
    "ticketId",
    "on_pushButton_clicked",
    "onCheckboxToggled",
    "checked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSbookflightwindowENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[17];
    char stringdata1[19];
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
    char stringdata14[22];
    char stringdata15[18];
    char stringdata16[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSbookflightwindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSbookflightwindowENDCLASS_t qt_meta_stringdata_CLASSbookflightwindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "bookflightwindow"
        QT_MOC_LITERAL(17, 18),  // "sendBookingDetails"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 9),  // "firstName"
        QT_MOC_LITERAL(47, 8),  // "lastName"
        QT_MOC_LITERAL(56, 11),  // "phoneNumber"
        QT_MOC_LITERAL(68, 15),  // "flightAvailable"
        QT_MOC_LITERAL(84, 13),  // "departureDate"
        QT_MOC_LITERAL(98, 10),  // "flyingFrom"
        QT_MOC_LITERAL(109, 8),  // "flyingTo"
        QT_MOC_LITERAL(118, 10),  // "seatNumber"
        QT_MOC_LITERAL(129, 9),  // "seatClass"
        QT_MOC_LITERAL(139, 9),  // "totalCost"
        QT_MOC_LITERAL(149, 8),  // "ticketId"
        QT_MOC_LITERAL(158, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(180, 17),  // "onCheckboxToggled"
        QT_MOC_LITERAL(198, 7)   // "checked"
    },
    "bookflightwindow",
    "sendBookingDetails",
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
    "ticketId",
    "on_pushButton_clicked",
    "onCheckboxToggled",
    "checked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSbookflightwindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,   11,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    0,   55,    2, 0x08,   13 /* Private */,
      15,    1,   56,    2, 0x08,   14 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Double, QMetaType::QString,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject bookflightwindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSbookflightwindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSbookflightwindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSbookflightwindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<bookflightwindow, std::true_type>,
        // method 'sendBookingDetails'
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
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCheckboxToggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void bookflightwindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<bookflightwindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendBookingDetails((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[11]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->onCheckboxToggled((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (bookflightwindow::*)(const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , const QString & , double , const QString & );
            if (_t _q_method = &bookflightwindow::sendBookingDetails; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *bookflightwindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *bookflightwindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSbookflightwindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int bookflightwindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void bookflightwindow::sendBookingDetails(const QString & _t1, const QString & _t2, const QString & _t3, const QString & _t4, const QString & _t5, const QString & _t6, const QString & _t7, const QString & _t8, const QString & _t9, double _t10, const QString & _t11)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t8))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t9))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t10))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t11))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
