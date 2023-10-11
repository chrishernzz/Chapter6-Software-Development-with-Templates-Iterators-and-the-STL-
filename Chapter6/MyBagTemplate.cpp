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

template<typename T>
void MyBagTemplate<T>::clearMyBag(){
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

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

template<typename T>
bool MyBagTemplate<T>::searchMyBag(const T& search) const{
    for (int i = 0; i < size; ++i){
        if (data[i] == search) {
            return true;
        }
    }
    return false;
}

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

template<typename T>
void MyBagTemplate<T>::sortMyBag(){
    sort(data, data + size);
}

template<typename T>
bool MyBagTemplate<T>::operator<(const MyBagTemplate<T>& obj) const{
    return size < obj.size;
}

template<typename T>
T& MyBagTemplate<T>::operator[](int index){
    if (index < 0 || index >= size){
        throw out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
const T& MyBagTemplate<T>::operator[](size_t index) const{
    if (index >= 0 && index < size){
        return data[index];
    }
    // Handle out-of-bounds access
    throw out_of_range("Index out of bounds");
}
template<typename T>
ostream& operator<<(ostream& out, const MyBagTemplate<T>& bag){
    for (int i = 0; i < bag.size; ++i){
        out << bag.data[i] << " ";
    }
    return out;
}
