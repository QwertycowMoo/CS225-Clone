/* Your code here! */
#include "dsets.h"


void DisjointSets::addelements (int num) {
    for (int i = 0; i < num; i++) {
        _data.push_back(-1);
    }
}

int DisjointSets::find(int elem) {
    if (_data[elem] <= -1) {
        return elem;     
    }
    _data[elem] = find(_data[elem]);
    return _data[elem];
}

void DisjointSets::setunion(int a, int b){
    if (size(a) < size(b)) {
        //join a to b
        int toJoin = find(a);
        int sizeA = size(toJoin);
        int joinTo = find(b);
        int sizeB = size(joinTo);
        _data[toJoin] = joinTo;
        _data[joinTo] = -(sizeA + sizeB);
    } else {
        //join b to a, handles the equal case
        int toJoin = find(b);
        int sizeB = size(toJoin);
        int joinTo = find(a);
        int sizeA = size(joinTo);
        _data[toJoin] = joinTo;
        _data[joinTo] = -(sizeA + sizeB);
    }
}

int DisjointSets::size(int elem) {
    while (_data[elem] > -1) {
        elem = _data[elem];
    }
    return abs(_data[elem]);
}
