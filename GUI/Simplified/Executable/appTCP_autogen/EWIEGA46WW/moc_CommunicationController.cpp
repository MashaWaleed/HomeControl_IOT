/****************************************************************************
** Meta object code from reading C++ file 'CommunicationController.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../TCP/CommunicationController.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CommunicationController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
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
struct qt_meta_stringdata_CLASSCommunicationControllerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSCommunicationControllerENDCLASS = QtMocHelpers::stringData(
    "CommunicationController",
    "dataReceived",
    "",
    "data",
    "temperatureChanged",
    "temperature",
    "humidityChanged",
    "humidity",
    "carbonChanged",
    "carbon",
    "doorBillChanged",
    "doorBill",
    "gateChanged",
    "gate",
    "clientsCountChanged",
    "count",
    "volumeChanged",
    "volume",
    "sendCommand",
    "command",
    "getTemperature",
    "getHumidity",
    "getCarbon",
    "getDoorBill",
    "getGate",
    "getClientsCount",
    "getVolume",
    "incrementVol",
    "decrementVol",
    "handleNewConnection",
    "handleReadyRead",
    "socketDisconnected",
    "checkClientAlive",
    "clientsCount"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCommunicationControllerENDCLASS_t {
    uint offsetsAndSizes[68];
    char stringdata0[24];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[19];
    char stringdata5[12];
    char stringdata6[16];
    char stringdata7[9];
    char stringdata8[14];
    char stringdata9[7];
    char stringdata10[16];
    char stringdata11[9];
    char stringdata12[12];
    char stringdata13[5];
    char stringdata14[20];
    char stringdata15[6];
    char stringdata16[14];
    char stringdata17[7];
    char stringdata18[12];
    char stringdata19[8];
    char stringdata20[15];
    char stringdata21[12];
    char stringdata22[10];
    char stringdata23[12];
    char stringdata24[8];
    char stringdata25[16];
    char stringdata26[10];
    char stringdata27[13];
    char stringdata28[13];
    char stringdata29[20];
    char stringdata30[16];
    char stringdata31[19];
    char stringdata32[17];
    char stringdata33[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCommunicationControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCommunicationControllerENDCLASS_t qt_meta_stringdata_CLASSCommunicationControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23),  // "CommunicationController"
        QT_MOC_LITERAL(24, 12),  // "dataReceived"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 4),  // "data"
        QT_MOC_LITERAL(43, 18),  // "temperatureChanged"
        QT_MOC_LITERAL(62, 11),  // "temperature"
        QT_MOC_LITERAL(74, 15),  // "humidityChanged"
        QT_MOC_LITERAL(90, 8),  // "humidity"
        QT_MOC_LITERAL(99, 13),  // "carbonChanged"
        QT_MOC_LITERAL(113, 6),  // "carbon"
        QT_MOC_LITERAL(120, 15),  // "doorBillChanged"
        QT_MOC_LITERAL(136, 8),  // "doorBill"
        QT_MOC_LITERAL(145, 11),  // "gateChanged"
        QT_MOC_LITERAL(157, 4),  // "gate"
        QT_MOC_LITERAL(162, 19),  // "clientsCountChanged"
        QT_MOC_LITERAL(182, 5),  // "count"
        QT_MOC_LITERAL(188, 13),  // "volumeChanged"
        QT_MOC_LITERAL(202, 6),  // "volume"
        QT_MOC_LITERAL(209, 11),  // "sendCommand"
        QT_MOC_LITERAL(221, 7),  // "command"
        QT_MOC_LITERAL(229, 14),  // "getTemperature"
        QT_MOC_LITERAL(244, 11),  // "getHumidity"
        QT_MOC_LITERAL(256, 9),  // "getCarbon"
        QT_MOC_LITERAL(266, 11),  // "getDoorBill"
        QT_MOC_LITERAL(278, 7),  // "getGate"
        QT_MOC_LITERAL(286, 15),  // "getClientsCount"
        QT_MOC_LITERAL(302, 9),  // "getVolume"
        QT_MOC_LITERAL(312, 12),  // "incrementVol"
        QT_MOC_LITERAL(325, 12),  // "decrementVol"
        QT_MOC_LITERAL(338, 19),  // "handleNewConnection"
        QT_MOC_LITERAL(358, 15),  // "handleReadyRead"
        QT_MOC_LITERAL(374, 18),  // "socketDisconnected"
        QT_MOC_LITERAL(393, 16),  // "checkClientAlive"
        QT_MOC_LITERAL(410, 12)   // "clientsCount"
    },
    "CommunicationController",
    "dataReceived",
    "",
    "data",
    "temperatureChanged",
    "temperature",
    "humidityChanged",
    "humidity",
    "carbonChanged",
    "carbon",
    "doorBillChanged",
    "doorBill",
    "gateChanged",
    "gate",
    "clientsCountChanged",
    "count",
    "volumeChanged",
    "volume",
    "sendCommand",
    "command",
    "getTemperature",
    "getHumidity",
    "getCarbon",
    "getDoorBill",
    "getGate",
    "getClientsCount",
    "getVolume",
    "incrementVol",
    "decrementVol",
    "handleNewConnection",
    "handleReadyRead",
    "socketDisconnected",
    "checkClientAlive",
    "clientsCount"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCommunicationControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       7,  186, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  146,    2, 0x06,    8 /* Public */,
       4,    1,  149,    2, 0x06,   10 /* Public */,
       6,    1,  152,    2, 0x06,   12 /* Public */,
       8,    1,  155,    2, 0x06,   14 /* Public */,
      10,    1,  158,    2, 0x06,   16 /* Public */,
      12,    1,  161,    2, 0x06,   18 /* Public */,
      14,    1,  164,    2, 0x06,   20 /* Public */,
      16,    1,  167,    2, 0x06,   22 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    1,  170,    2, 0x0a,   24 /* Public */,
      20,    0,  173,    2, 0x0a,   26 /* Public */,
      21,    0,  174,    2, 0x0a,   27 /* Public */,
      22,    0,  175,    2, 0x0a,   28 /* Public */,
      23,    0,  176,    2, 0x0a,   29 /* Public */,
      24,    0,  177,    2, 0x0a,   30 /* Public */,
      25,    0,  178,    2, 0x0a,   31 /* Public */,
      26,    0,  179,    2, 0x0a,   32 /* Public */,
      27,    0,  180,    2, 0x0a,   33 /* Public */,
      28,    0,  181,    2, 0x0a,   34 /* Public */,
      29,    0,  182,    2, 0x08,   35 /* Private */,
      30,    0,  183,    2, 0x08,   36 /* Private */,
      31,    0,  184,    2, 0x08,   37 /* Private */,
      32,    0,  185,    2, 0x08,   38 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    3,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   19,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Float,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       5, QMetaType::Float, 0x00015001, uint(1), 0,
       7, QMetaType::Float, 0x00015001, uint(2), 0,
       9, QMetaType::Float, 0x00015001, uint(3), 0,
      11, QMetaType::Int, 0x00015001, uint(4), 0,
      13, QMetaType::Int, 0x00015001, uint(5), 0,
      33, QMetaType::Int, 0x00015001, uint(6), 0,
      17, QMetaType::Int, 0x00015001, uint(7), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject CommunicationController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSCommunicationControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCommunicationControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCommunicationControllerENDCLASS_t,
        // property 'temperature'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
        // property 'humidity'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
        // property 'carbon'
        QtPrivate::TypeAndForceComplete<float, std::true_type>,
        // property 'doorBill'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'gate'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'clientsCount'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'volume'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CommunicationController, std::true_type>,
        // method 'dataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'temperatureChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'humidityChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'carbonChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'doorBillChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'gateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'clientsCountChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'volumeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sendCommand'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'getTemperature'
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'getHumidity'
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'getCarbon'
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'getDoorBill'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getGate'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getClientsCount'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getVolume'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'incrementVol'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'decrementVol'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleNewConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'socketDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'checkClientAlive'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CommunicationController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommunicationController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataReceived((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 1: _t->temperatureChanged((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 2: _t->humidityChanged((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 3: _t->carbonChanged((*reinterpret_cast< std::add_pointer_t<float>>(_a[1]))); break;
        case 4: _t->doorBillChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->gateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->clientsCountChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->volumeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->sendCommand((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 9: { float _r = _t->getTemperature();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 10: { float _r = _t->getHumidity();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 11: { float _r = _t->getCarbon();
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->getDoorBill();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 13: { int _r = _t->getGate();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: { int _r = _t->getClientsCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: { int _r = _t->getVolume();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: _t->incrementVol(); break;
        case 17: _t->decrementVol(); break;
        case 18: _t->handleNewConnection(); break;
        case 19: _t->handleReadyRead(); break;
        case 20: _t->socketDisconnected(); break;
        case 21: _t->checkClientAlive(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CommunicationController::*)(const QByteArray & );
            if (_t _q_method = &CommunicationController::dataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CommunicationController::*)(float );
            if (_t _q_method = &CommunicationController::temperatureChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CommunicationController::*)(float );
            if (_t _q_method = &CommunicationController::humidityChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CommunicationController::*)(float );
            if (_t _q_method = &CommunicationController::carbonChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CommunicationController::*)(int );
            if (_t _q_method = &CommunicationController::doorBillChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CommunicationController::*)(int );
            if (_t _q_method = &CommunicationController::gateChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CommunicationController::*)(int );
            if (_t _q_method = &CommunicationController::clientsCountChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CommunicationController::*)(int );
            if (_t _q_method = &CommunicationController::volumeChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<CommunicationController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< float*>(_v) = _t->getTemperature(); break;
        case 1: *reinterpret_cast< float*>(_v) = _t->getHumidity(); break;
        case 2: *reinterpret_cast< float*>(_v) = _t->getCarbon(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getDoorBill(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getGate(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getClientsCount(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->getVolume(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *CommunicationController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommunicationController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCommunicationControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CommunicationController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 22;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CommunicationController::dataReceived(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CommunicationController::temperatureChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CommunicationController::humidityChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CommunicationController::carbonChanged(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CommunicationController::doorBillChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void CommunicationController::gateChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void CommunicationController::clientsCountChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CommunicationController::volumeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
