#ifndef USER_H
#define USER_H

#include <QString>

//User.h
//Defines a user
//Based on teamJAG's DesignReview p.29

//User class definition
class User {
public:
        enum role{
            MedicalClerk,
            MedicalAdministrator,
            SystemAdministrator
        };

        User(int, QString, QString, int, bool, role);
        ~User();

        int getId();
        QString getName();
        QString getPasswordHash();
        bool getLocked();
        void setLocked(bool);
        User::role getUserRole();
        QString getUserRoleStr(int);
private:
        int id;
        QString name;
        QString passwordHash;
        int defaultRegionId;
        bool locked;
        role userRole;
        QString userStr;
};

#endif // USER_H
