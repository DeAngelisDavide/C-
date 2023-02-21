//
// Created by 39331 on 12/10/2021.
//

#ifndef BLOCKCHAINBANCA_TRANSAZIONI_H
#define BLOCKCHAINBANCA_TRANSAZIONI_H
#include <iostream>

class transazioni {
protected:
    std::string from;
    std::string to;
    float qt;
public:
    transazioni(const std::string, const std::string, float);

    const std::string &getFrom() const;

    void setFrom(const std::string &from);

    const std::string &getTo() const;

    void setTo(const std::string &to);

    float getQt() const;

    void setQt(float qt);

    void print();
};


#endif //BLOCKCHAINBANCA_TRANSAZIONI_H
