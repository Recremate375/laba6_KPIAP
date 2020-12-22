#pragma once
#include <iostream>
#include <new>

template<typename T>
class FIFO
{
private:
    T* arr;
    int count;
public:
    FIFO()
    {
        this->count = 0;
    }
    FIFO(T count)
    {
        this->count = count;
    }
    FIFO(const FIFO& object)
    {
        this->count = object.count;

        try
        {
            arr = new T[count];
            for (int i = 0; i < this->count; i++)
            {
                this->arr[i] = object.arr[i];
            }
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;
            count = 0;
        }
    }

    void push_back(T item)
    {
        T* arr2;
        arr2 = arr;
        try
        {
            arr = new T[count + 1]
                for (int i = 0; i < count; i++)
                {
                    arr[i] = arr2[i];
                }
            arr[count] = item;
            count++;
            if (count > 1)
            {
                delete[] arr2;
            }
        }
        catch(bad_alloc e)
        {
            cout << e.what() << endl;
            arr = arr2;
        }
    }
    T pop_front()
    {
        if (count == 0)
        {
            return 0;
        }
        T item;
        item = arr[0];
        try {
            T* arr2;
            arr2 = new T[count - 1];
            count--;
            for (int i = 0; i < count; i++)
            {
                arr2[i] = arr[i + 1];
            }
            if (count > 0)
            {
                delete[] arr;
            }
            arr = arr2;
            return item;
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;
            return 0;
        }
    }
    void sort()
    {
        cout << "Do you want to sort in ascending or descending order? \n 1 - ascending;\n 2 - descending;\n 0 - exit;" << endl;
        int choice;
        choice = input_int();
        switch (choice)
        {
        case 0:
        {
            break;
        }
        case 1: 
        {
            for (int i = 0; i < count; i++)
            {
                int j = i + 1;
                if (arr[i] > arr[j])
                {
                    T tmp;
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < count; i++)
            {
                int j = i + 1;
                if (arr[i] < arr[j])
                {
                    T tmp;
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
            break;
        }
        }
    }
    void find()
    {
        cout << "Enter the element, do you want to find." << endl;
        T element;
        cin >> element;
        int i = 0;
        while (arr[i] != element)
        {
            if (arr[i] == element)
            {
                cout << "Your element is "<< i+1 << " into the FIFO." << endl;
                show();
            }
            i++;
        }
    }
    void show()
    {
        cout << "FIFO:" << endl;
        for (int i = 0; i < this->count; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
    void Get_First_Element()
    {
        if (count > 0)
        {
            return arr[0];
        }
        else
        {
            return 0;
        }
    }
    FIFO& operator=(const FIFO& obj)
    {
        T* arr2;
        try
        {
            arr2 = new T[obj.count];
            if (this->count > 0)
            {
                delete[] p;
            }
            arr = arr2;
            count = obj.count;
            for (int i = 0; i < count; i++)
            {
                arr[i] = obj.arr[i]
            }
        }
        catch (bad_alloc e)
        {
            cout << e.what() << endl;
        }
        return *this;
    }
    ~FIFO()
    {
        if (count > 0)
        {
            delete[] arr;
        }
    }
};

template<>
class FIFO<char*>
{
private:
    char* str;
    int count;
public:
    FIFO(char* stroka)
    {
        this->str = stroka;
    }
    void show()
    {
        std::cout << this->str << std::endl;
    }
    void push_back(char* item)
    {
        
    }
    ~FIFO()
    { }
};