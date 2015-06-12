#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include<stdexcept>
template <class T>
class  Vector
{
private:
    unsigned int sizeValue;
    unsigned int capacityValue;
    T* buffer;
public:
    Vector();
    Vector(unsigned int size); //+3
    Vector(unsigned int size, const T & initial);
    Vector(const Vector<T>& v);
    ~Vector();
    Vector<T> & operator = (const Vector<T> &);
    void push_back(const T& value);
    void pop_back();
    void resize(unsigned int size, T val);
    T& front();
    T& back();
    void insert(int index, T value);
    void erase(int index);
    T & operator[](unsigned int index);
    unsigned int size() const;
    unsigned int capacity() const;
    bool empty() const;
    void clear();

    void shring_to_fit();
    void reserve(unsigned int capacity); //+1
    void swap(Vector<T>& v); //+2
};
template<class T>
Vector<T>::Vector()
{
    capacityValue = 1;
    sizeValue = 0;
    buffer = new T[1];
}
template<class T>
Vector<T>::Vector(unsigned int size)
{
    capacityValue =size;
    sizeValue=0;
    buffer = new T[capacityValue];
}
template<class T>
Vector<T>::Vector(unsigned int size, const T& initial)
{
    sizeValue = 0;
    capacityValue = size;
    buffer = new T [capacityValue];
    for (unsigned int i = 0; i < size; i++)
        buffer[i] = initial;
}
template<class T>
Vector<T>::Vector(const Vector<T> & v)
{
    sizeValue = v.sizeValue;
    capacityValue = v.capacityValue;
    buffer = new T[sizeValue];
    for (unsigned int i = 0; i < sizeValue; i++)
        buffer[i] = v.buffer[i];
}
template<class T>
Vector<T>::~Vector()
{
    delete[] buffer;
}
template<class T>
Vector<T>& Vector<T>::operator = (const Vector<T> & v)
{
    delete[] buffer;
    sizeValue = v.sizeValue;
    capacityValue = v.capacityValue;
    buffer = new T [capacityValue];
    for (unsigned int i = 0; i < sizeValue; i++)
        buffer[i] = v.buffer[i];
    return *this;
}
template<class T>
void Vector<T>::push_back(const T & v)
{
    /*
        Incidentally, one common way of regrowing an array is to double the size as needed.
        This is so that if you are inserting n items at most only O(log n) regrowths are performed
        and at most O(n) space is wasted.
    */
    if (sizeValue >= capacityValue)
    {
        reserve(capacityValue*2);
        //Log++;
    }
    buffer [sizeValue++] = v;
}
template<class T>
void Vector<T>::pop_back()
{

    if(sizeValue==0) cout<<"Vector is empty"<<endl;//throw std::out_of_range("Vector is empty. There are no elements!");
    if(((double)(sizeValue +1) / capacityValue) < 0.25)
    {
        T *b=new T [capacityValue/2];
        capacityValue/=2;
        copy(buffer,buffer+sizeValue+1,b);
        delete[] buffer;
        buffer=b;
    }
    sizeValue--;
}
template<class T>
void Vector<T>::resize(unsigned int size, T val=0)
{
    //Log = ceil(log((double) size) / log(2.0));

    if(sizeValue<size) {reserve(size);
    for(int i=sizeValue; i<size; i++) buffer[i]=val;
    }
    sizeValue=size;
}
template<class T>
T& Vector<T>::front()
{
    return buffer[0];
}
template<class T>
T& Vector<T>::back()
{
    return buffer[sizeValue - 1];
}
template<class T>
void Vector<T>::insert(int index, T value)
{
    if(index>=0 && index<sizeValue)
    {
        push_back(buffer[sizeValue-1]);
        //nz dali sizevalue shte se e uvelichilo s edno za sledvashtiq for dali da e -1 ili -2
        for(int i=sizeValue-2; i>index; i--)
        {
            buffer[i]=buffer[i-1];
        }
        buffer[index]=value;
    }
    else throw std::invalid_argument("Dont have that much items");
}
template<class T>
void Vector<T>::erase(int index)
{
    if(index>=0 && index<sizeValue)
    {
        for(int i=index; i<sizeValue-1; i++) buffer[i]=buffer[i+1];
        sizeValue--;
    }
    else throw std::invalid_argument("Dont have such element");
}
template<class T>
T& Vector<T>::operator[](unsigned int index)
{
    if(index>=0 && index<sizeValue)
        return buffer[index];
    else throw std::invalid_argument("Your index in [] is invalid. Dont have such element.");
}
template<class T>
unsigned int Vector<T>::size() const
{
    return sizeValue;
}
template<class T>
unsigned int Vector<T>::capacity()const
{
    return capacityValue;
}
template <class T>
bool Vector<T>:: empty() const
{
    return sizeValue == 0;
}
template <class T>
void Vector<T>::clear()
{
    capacityValue = 0;
    sizeValue = 0;
    delete[] buffer;
    buffer=new T[1];
}


template<class T>
void Vector<T>::shring_to_fit()
{
    T *newBuffer=new T [sizeValue];
    capacityValue=sizeValue;
    copy(buffer,buffer+sizeValue+1,newBuffer);
    delete[] buffer;
    buffer=newBuffer;
}
template<class T>
void Vector<T>::reserve(unsigned int capacity)
{
    if(capacity>capacityValue)
    {
        T * newBuffer = new T[capacity];

        for (unsigned int i = 0; i < sizeValue; i++)
            newBuffer[i] = buffer[i];

        capacityValue = capacity;
        delete[] buffer;
        buffer = newBuffer;
    }
}
template<class T>
void Vector<T>::swap(Vector<T>& v)
{
    Vector<T> copyVector(v);
    v.sizeValue=sizeValue;
    v.capacityValue=capacityValue;
    v.buffer = new T[sizeValue];
    for (unsigned int i = 0; i < sizeValue; i++)
        v.buffer[i] = buffer[i];
    sizeValue = copyVector.sizeValue;
    capacityValue = copyVector.capacityValue;
    buffer = new T[sizeValue];
    for (unsigned int i = 0; i < sizeValue; i++)
        buffer[i] = copyVector.buffer[i];
    copyVector.clear();
}


#endif // VECTOR_H_INCLUDED
