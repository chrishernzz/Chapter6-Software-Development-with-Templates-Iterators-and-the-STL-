#include "MyBagTemplate.h"

//precondition: going to call my defaults constructor
//postcondition: going to initialize them and passing in the template
template<typename T>
MyBagTemplate<T>::MyBagTemplate():data(nullptr), size(0), capacity(0){}
//precondition: going to call my constructor
//postcondition: going to be allocating new to the data and newCapacity with size using templates
template<typename T>
MyBagTemplate<T>::MyBagTemplate(int newCapacity): data(new T[newCapacity]), size(0), capacity(newCapacity){}
//precondition: going to call my deconstructor
//postcondition: going to deallocate the memory so it does not leak, using templates
template<typename T>
MyBagTemplate<T>::~MyBagTemplate(){
	delete[] data;
}

//precondition: going to get the size , Template way
//postcondition: going to return the private size
template<typename T>
int MyBagTemplate<T>::getSize() const{
	return size;
}
//precondition: going to get the new size, Template way
//postcondition: going to set the private size with the new size member
template<typename T>
void MyBagTemplate<T>::setSize(int newSize){
	size = newSize;
}
//precondition: going to call the myBag (template)
//postcondition: going to then clear the myBag (make it empty)
template<typename T>
void MyBagTemplate<T>::clearMyBag(){
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}
//precondition: going to call the myBag (template)
//postcondition: going to then insert to the myBag (return the value)
template<typename T>
void MyBagTemplate<T>::insertMyBag(const T& insert){
    if (size >= capacity){
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[newCapacity];

        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        //deallocate the memory so it does not leak
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    data[size++] = insert;
}
//precondition: going to call the myBag (template)
//postcondition: going to then search the myBag (return the value if found)
template<typename T>
bool MyBagTemplate<T>::searchMyBag(const T& search) const{
    for (int i = 0; i < size; ++i){
        if (data[i] == search) {
            return true;
        }
    }
    return false;
}
//precondition: going to call the myBag (template)
//postcondition: going to then remove the myBag (return the value and remove it)
template<typename T>
bool MyBagTemplate<T>::removeMyBag(const T& remove){
    int index = -1;
    for (int i = 0; i < size; ++i){
        if (data[i] == remove){
            index = i;
            break;
        }
    }
    if (index != -1){
        for (int i = index; i < size - 1; ++i){
            data[i] = data[i + 1];
        }
        size--;
        return true;
    }
    return false;
}
//precondition: going to call the myBag (template)
//postcondition: going to then search the myBag (return the values in sorted form)
template<typename T>
void MyBagTemplate<T>::sortMyBag(){
    sort(data, data + size);
}
//precondition: going to call the myBag (template)
//postcondition: going to then overload the < operator
template<typename T>
bool MyBagTemplate<T>::operator<(const MyBagTemplate<T>& obj) const{
    return size < obj.size;
}
//precondition: going to call the myBag (template)
//postcondition: going to then overload the [] operator
template<typename T>
T& MyBagTemplate<T>::operator[](int index){
    if (index < 0 || index >= size){
        throw out_of_range("Index out of range");
    }
    return data[index];
}
//precondition: going to call the myBag (template)
//postcondition: going to then overload the [] operator for the size
template<typename T>
const T& MyBagTemplate<T>::operator[](size_t index) const{
    if (index >= 0 && index < size){
        return data[index];
    }
    // Handle out-of-bounds access
    throw out_of_range("Index out of bounds");
}
//precondition: going to call the myBag (template)
//postcondition: going to return the cout of the bag
template<typename T>
ostream& operator<<(ostream& out, const MyBagTemplate<T>& bag){
    for (int i = 0; i < bag.size; ++i){
        out << bag.data[i] << " ";
    }
    return out;
}
//precondition: going to call the myBag (template)
//postcondition: going to then add the myBag (call the ensureCpacity() function)
template<typename T>
void MyBagTemplate<T>::add(double value) {
    if (size == capacity) {
        ensureCapacity((capacity == 0) ? 1 : capacity * 2);
    }
    data[size++] = value;
}
//precondition: going to call the myBag (template)
//postcondition: going to then clear the myBag (its going to be empty)
template<typename T>
void MyBagTemplate<T>::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}
//precondition: going to call the myBag (template)
//postcondition: going to then check the ensure capacity the myBag
template<typename T>
void MyBagTemplate<T>::ensureCapacity(int newCapacity) {
    if (newCapacity > capacity) {
        double* newData = new double[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
}
//precondition: going to call the myBag (template)
//postcondition: going to then check whats in the myBag
template<typename T>
bool MyBagTemplate<T>::contains(double value) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}
//precondition: going to print the information in template form
//postcondition: going to create a menu that accepts 
template<typename T>
void MyBagTemplate<T>::menuInformation(){
    system("cls");
    char option;
    do {
    beginning:
        cout << "\n\t\t2> emplate MyBag<double> container";
        cout << "\n\t\t" << string(82, char(205));
        cout << "\n\t\t\tA> clear";
        cout << "\n\t\t\tB> insert";
        cout << "\n\t\t\tC> search";
        cout << "\n\t\t\tD> remove";
        cout << "\n\t\t\tE> sort";
        cout << "\n\t\t\tF> display";
        cout << "\n\t\t" << string(82, char(205));
        cout << "\n\t\t\t0> return";
        cout << "\n\t\t" << string(82, char(205)) << "\n";
        option = inputChar("\t\t\tOption: ", (static_cast<string>("ABCDEF0")));

        switch (toupper(option)) {
        case 'A': {
            clear();
            cout << "\n\t\t\tMy bag is cleared of all elements.";
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'B': {
            double newValue = inputDouble("\n\t\t\tEnter a value and insert into MyBag: ");
            add(newValue);
            cout << "\n\t\t\tValue " << newValue << " has been inserted into MyBag.";
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'C': {
            //check if MyBag is nullptr, if empty, send a warning
            if (data == 0) {
                cout << "\n\t\t\tMyBag is empty.\n\n";
                system("pause");
                system("cls");
                goto beginning;
            }
            double search = inputInteger("\n\t\t\tEnter a value to search from MyBag: ");
            bool found = contains(search);

            if (found) {
                cout << "\n\t\t\tValue " << search << " is in MyBag.";
            }
            else {
                cout << "\n\t\t\tValue " << search << " is not in MyBag.";
            }
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'D': {
            //check if MyBag is nullptr, if empty, send a warning
            if (data == 0) {
                cout << "\n\t\t\tMyBag is empty.\n\n";
                system("pause");
                system("cls");
                goto beginning;
            }
            int index = inputInteger("\n\t\t\tEnter an index to be deleted: ", 0, size - 1);
            cout << "\n";
            if (index < 0 || index >= size) {
                cout << "\n\t\t\tInvalid index or index out of range.";
            }
            else {
                double removeValue = data[index];
                for (int i = index; i < size - 1; i++) {
                    data[i] = data[i + 1];
                }
                size--;
                cout << "\n\t\t\tValue " << removeValue << " at subscript " << index << " has been deleted.";
            }
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'E': {
            //check if MyBag is nullptr, if empty, send a warning
            if (data == 0) {
                cout << "\n\t\t\tMyBag is empty.\n\n";
                system("pause");
                system("cls");
                goto beginning;
            }
            sort(data, data + size);
            cout << "\n\t\t\tMyBag has been sorted.";
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case 'F': {
            //check if MyBag is nullptr, if empty, send a warning
            if (data == 0) {
                cout << "\n\t\t\tMyBag is empty.\n\n";
                system("pause");
                system("cls");
                goto beginning;
            }
            cout << "\n\t\t\tMyBag: \n";
            for (int i = 0; i < size; i++) {
                cout << "\n\t\t\t[" << i << "] - " << data[i];
            }
            cout << "\n\n";
            system("pause");
            system("cls");
        }
                break;
        case '0': {
            return;
        }
        }
    } while (true);
}