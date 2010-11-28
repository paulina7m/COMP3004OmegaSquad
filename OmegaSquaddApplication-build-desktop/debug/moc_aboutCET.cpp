/****************************************************************************
** Meta object code from reading C++ file 'aboutCET.h'
**
** Created: Sun Nov 28 17:17:48 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OmegaSquaddApplication/aboutCET.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aboutCET.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AboutCETDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AboutCETDialog[] = {
    "AboutCETDialog\0\0dialogToBeClosed()\0"
    "closeDialog()\0"
};

const QMetaObject AboutCETDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AboutCETDialog,
      qt_meta_data_AboutCETDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AboutCETDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AboutCETDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AboutCETDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AboutCETDialog))
        return static_cast<void*>(const_cast< AboutCETDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int AboutCETDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: dialogToBeClosed(); break;
        case 1: closeDialog(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void AboutCETDialog::dialogToBeClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
