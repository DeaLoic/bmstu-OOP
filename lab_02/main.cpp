#include "Set.cpp"
#include <iostream>
using namespace std;

template <typename T>
void out(Set<T> set);

int main()
{
    cout << "Creation\n";
    cout << "Create empty: ";
    Set<int> emptySet;
    out(emptySet);

    cout << "Create from initializer_list: ";
    Set<int> set({1,2,3});
    out(set);

    cout << "Create from set: ";
    Set<int> secondSet(set);
    out(secondSet);

    cout << "\nIsEqual  " << set.IsEqual(emptySet) << "     " << set.IsEqual(secondSet);
    cout << "\n Is Equal by operation ==: " << (secondSet == emptySet) << "   and != " << (secondSet != emptySet) << "\n";
    cout << "\nOperation on element\n";
    cout << "Adding operation +: ";
    out(set + 4);
    cout << "Source set: ";
    out(set);

    cout << "Adding operation +=: ";
    set += 4;
    out(set);

    cout << "Adding by method Add: ";
    set.Add(6);
    out(set);

    cout << "\nRemoving\n";
    cout << "Removing operation -: ";
    out(set - 2);
    cout << "Source set: ";
    out(set);

    cout << "Removing operation -=: ";
    set -= 2;
    out(set);

    cout << "Removing by method Remove: ";
    set.Remove(6);
    out(set);

    cout << "\nIsContain: " << set.IsContain(1) << "    " << set.IsContain(2) << "\n";
    cout << "Clear: ";
    set.Clear();
    out(set);

    cout << "\nAssignment\nBy set lvalue: ";
    set = secondSet;
    out(set);
    cout << "By set rvalue: ";
    set = secondSet + 9;
    out(set);
    cout << "By initializer_list: ";
    set = {1, 3, 4, 5, 7, 8, 9, 11};
    out(set);

    cout << "\nUnion\nBy method: ";
    emptySet = set;
    emptySet.Union(secondSet);
    out(emptySet);
    cout << "By operator +: ";
    out(set + secondSet);
    cout << "By operation +=: ";
    emptySet = set;
    emptySet += secondSet;
    out(emptySet);

    cout << "\nIntersection\nBy method: ";
    emptySet = set;
    emptySet.Intersection(secondSet);
    out(emptySet);
    cout << "By operator *: ";
    out(set * secondSet);
    cout << "By operation *=: ";
    emptySet = set;
    emptySet *= secondSet;
    out(emptySet);
    
    cout << "\nDifference\nBy method: ";
    emptySet = set;
    emptySet.Difference(secondSet);
    out(emptySet);
    cout << "By operator -: ";
    out(set - secondSet);
    cout << "By operation -=: ";
    emptySet = set;
    emptySet -= secondSet;
    out(emptySet);

    cout << "\nSymmetricDifference\nBy method: ";
    emptySet = set;
    emptySet.SymmetricDifference(secondSet);
    out(emptySet);
    cout << "By operator /: ";
    out(set / secondSet);
    cout << "By operation /=: ";
    emptySet = set;
    emptySet /= secondSet;
    out(emptySet);

    cout << "\nOut by iterator: ";
    for (auto element : emptySet)
    {
        cout << element << " ";
    }

    return 1;
}

template <typename T>
void out(Set<T> set)
{
    cout << set << "\n";
}