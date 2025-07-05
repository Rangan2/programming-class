#include "id_generator.h"

unsigned int IDGeneratorUtil::getNewID() {
    return ++id;
}

bool IDGeneratorUtil::isValidID(unsigned int checkId) {
    return checkId <= id;
}