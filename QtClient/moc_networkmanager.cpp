/****************************************************************************
** Meta object code from reading C++ file 'networkmanager.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "networkmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NetworkManager[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   16,   15,   15, 0x05,
      46,   40,   15,   15, 0x05,
      72,   66,   15,   15, 0x05,
      93,   66,   15,   15, 0x05,
     110,   66,   15,   15, 0x05,
     125,   66,   15,   15, 0x05,
     142,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     157,   15,   15,   15, 0x0a,
     182,  165,   15,   15, 0x0a,
     214,   15,  210,   15, 0x0a,
     229,   15,   15,   15, 0x0a,
     253,  244,   15,   15, 0x0a,
     271,   15,   15,   15, 0x0a,
     303,  290,   15,   15, 0x0a,
     330,  322,   15,   15, 0x2a,
     345,   15,   15,   15, 0x2a,
     358,  353,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_NetworkManager[] = {
    "NetworkManager\0\0text\0writeText(QString)\0"
    "score\0newPlayerScore(int)\0value\0"
    "newHealthPoints(int)\0newPlayerId(int)\0"
    "newTeamId(int)\0newIdInTeam(int)\0"
    "disconnected()\0start()\0event,key_status\0"
    "process_key(QKeyEvent*,int)\0int\0"
    "network_init()\0set_rand_key()\0newLogin\0"
    "setLogin(QString)\0disconnectClient()\0"
    "ip_addr,port\0setIP(QString,int)\0ip_addr\0"
    "setIP(QString)\0setIP()\0team\0"
    "setRequestedTeam(int)\0"
};

void NetworkManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NetworkManager *_t = static_cast<NetworkManager *>(_o);
        switch (_id) {
        case 0: _t->writeText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->newPlayerScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->newHealthPoints((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->newPlayerId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->newTeamId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->newIdInTeam((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->disconnected(); break;
        case 7: _t->start(); break;
        case 8: _t->process_key((*reinterpret_cast< QKeyEvent*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: { int _r = _t->network_init();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: _t->set_rand_key(); break;
        case 11: _t->setLogin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->disconnectClient(); break;
        case 13: _t->setIP((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->setIP((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->setIP(); break;
        case 16: _t->setRequestedTeam((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NetworkManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NetworkManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NetworkManager,
      qt_meta_data_NetworkManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NetworkManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NetworkManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NetworkManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkManager))
        return static_cast<void*>(const_cast< NetworkManager*>(this));
    return QObject::qt_metacast(_clname);
}

int NetworkManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void NetworkManager::writeText(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetworkManager::newPlayerScore(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NetworkManager::newHealthPoints(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void NetworkManager::newPlayerId(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NetworkManager::newTeamId(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void NetworkManager::newIdInTeam(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void NetworkManager::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
