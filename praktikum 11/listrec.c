#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"

Address newNode(ElType x)
{
    Address p = (Address)malloc(sizeof(Node));
    if (p != NIL)
    {
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

boolean isEmpty(List l)
{
    return l == NIL;
}

boolean isOneElmt(List l)
{
    return !isEmpty(l) && NEXT(l) == NIL;
}

ElType head(List l)
{
    return INFO(l);
}

List tail(List l)
{
    return NEXT(l);
}

List konso(List l, ElType e)
{
    Address new = newNode(e);
    if (new != NIL)
    {
        NEXT(new) = l;
        return new;
    }
    return l;
}

List konsb(List l, ElType e)
{
    if (isEmpty(l))
        return konso(l, e);
    NEXT(l) = konsb(tail(l), e);
    return l;
}

List copy(List l)
{
    if (isEmpty(l))
        return NIL;
    return konso(copy(tail(l)), head(l));
}

List concat(List l1, List l2)
{
    if (isEmpty(l1))
        return copy(l2);
    return konso(concat(tail(l1), l2), head(l1));
}

int length(List l)
{
    if (isEmpty(l))
        return 0;
    return 1 + length(tail(l));
}

boolean isMember(List l, ElType x)
{
    if (isEmpty(l))
        return false;
    if (head(l) == x)
        return true;
    return isMember(tail(l), x);
}

void displayList(List l)
{
    if (!isEmpty(l))
    {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}

List insertAt(List l, ElType e, int idx)
{
    if (idx != 0) {
        return konso(l, e);
    } else {
        return konsb(insertAt(l, e, idx--), head(l));
    }
}


List deleteFirst(List l){
    return NEXT(l);
}

List deleteAt(List l, int idx){
    if (idx == 0) {
        return tail(l);
    } else {
        return konsb(deleteAt(l, idx--), head(l));
    }
}

List deleteLast(List l) {
    if (isOneElmt(l)) {
        return NIL;
    } else {
        return konsb(deleteLast(tail(l)), head(l));
    }
}

List inverseList(List l)
{
    if (isEmpty(l))
        return l;
    return konsb(inverseList(tail(l)), head(l));
}

void splitPosNeg(List l, List *l1, List *l2)
{
    if (isEmpty(l))
    {
        *l1 = NULL;
        *l2 = NULL;
    }
    else if (isOneElmt(l))
    {
        *l1 = *l2 = NULL;
        if (head(l) >= 0)
            *l1 = konso(*l1, head(l));
        else
            *l2 = konso(*l2, head(l));
    }
    else
    {
        if (head(l) >= 0)
        {
            splitPosNeg(tail(l), l1, l2);
            *l1 = konso(*l1, head(l));
        }
        else
        {
            splitPosNeg(tail(l), l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }
}

void splitOnX(List l, ElType x, List *l1, List *l2)
{
    if (isEmpty(l))
    {
        *l1 = NULL;
        *l2 = NULL;
    }
    else if (isOneElmt(l))
    {
        *l1 = *l2 = NULL;
        if (head(l) < x)
            *l1 = konso(*l1, head(l));
        else
            *l2 = konso(*l2, head(l));
    }
    else
    {
        if (head(l) < x)
        {
            splitOnX(tail(l), x, l1, l2);
            *l1 = konso(*l1, head(l));
        }
        else
        {
            splitOnX(tail(l), x, l1, l2);
            *l2 = konso(*l2, head(l));
        }
    }
}

List removeDuplicate(List l, List unique) {
    if (isEmpty(l)) {
        return unique;
    } else {
        if (!isMember(unique, INFO(l))) {
            konso(unique, INFO(l));
        }
        return removeDuplicate(tail(l), unique);
    }
}