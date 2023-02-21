//
// Created by 39331 on 12/10/2021.
//

#include "transazioni.h"

transazioni::transazioni(const std::string from, const std::string to, float qt) : from(from), to(to), qt(qt) {}

const std::string &transazioni::getFrom() const {
    return from;
}

void transazioni::setFrom(const std::string &from) {
    transazioni::from = from;
}

const std::string &transazioni::getTo() const {
    return to;
}

void transazioni::setTo(const std::string &to) {
    transazioni::to = to;
}

float transazioni::getQt() const {
    return qt;
}

void transazioni::setQt(float qt) {
    transazioni::qt = qt;
}

void transazioni::print() {
    std::cout<<"From: "<<from<<std::endl<<"To: "<<to<<std::endl<<"Qt: "<<qt<<std::endl;
}


