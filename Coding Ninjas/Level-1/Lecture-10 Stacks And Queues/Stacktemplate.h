template <typename T>

class StackUsingTemplate
{
    T *data;
    int nextIndex;
    int capacity;

public:
    StackUsingTemplate()
    {
        data = new T[4];
        nextIndex = 0;
        capacity = 4;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(T element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[capacity * 2];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = capacity * 2;
        }
        data[nextIndex] = element;
        nextIndex++;
        return;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "LIST EMPTY\n";
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "LIST IS EMPTY\n";
            return 0;
        }
        return data[nextIndex - 1];
    }
};