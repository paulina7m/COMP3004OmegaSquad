#include "User.h"

User::User(int anId, QString aName, QString aPasswordHash, int aDefaultRegionId, bool isLocked, role aRole):id(anId), name(aName), passwordHash(aPasswordHash), defaultRegionId(aDefaultRegionId), locked(isLocked), userRole(aRole) {}
User::~User() {}

int User::getId() {
    return id;
}

QString User::getName() {
    return name;
}

QString User::getPasswordHash() {
    return passwordHash;
}

bool User::getLocked() {
    return locked;
}

void User::setLocked(bool changeLock) {
    locked = changeLock;
}

User::role User::getUserRole() {
    return userRole;
}
