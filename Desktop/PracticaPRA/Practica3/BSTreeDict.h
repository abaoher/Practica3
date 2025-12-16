#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <string>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict : public Dict<V> {

private:
    BSTree<TableEntry<V>>* tree;

public:
    BSTreeDict() {
        tree = new BSTree<TableEntry<V>>();
    }

    ~BSTreeDict() override {
        delete tree;
    }

    int entries() override {
        return tree->size();
    }

    void insert(std::string key, V value) override {
        tree->insert(TableEntry<V>(key, value));
    }

    V search(std::string key) override {
        return tree->search(TableEntry<V>(key)).value;
    }

    V remove(std::string key) override {
        V val = search(key);
        tree->remove(TableEntry<V>(key));
        return val;
    }

    V operator[](std::string key) {
        return search(key);
    }

    friend std::ostream& operator<<(std::ostream &out,
                                    const BSTreeDict<V> &bs) {
        out << *(bs.tree);
        return out;
    }
};

#endif

