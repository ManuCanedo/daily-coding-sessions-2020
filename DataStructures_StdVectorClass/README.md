## Recreation of the STL Vector Class
<br/>

Vector.h contains the definition of the Vector Class including the following methods:

    Vector(){}
    ~Vector(){}
    
    void PopBack(){}
    void Clear(){}

    T PushBack(const T&){}
    T PushBack(T&&){}

    template <typename... Args>
    T &EmplaceBack(Args &&... args){}

    const T &operator[](size_t) const {}
    T &operator[](size_t) {}
    
    size_t Size() const {}

Vector3AndMain.cpp contains the definition of a Vector3 struct including the following methods:

    Vector3() {}
    Vector3(float) {}
    Vector3(float, float, float) {}
    ~Vector3() {}
    
    Vector3(const Vector3&) {}
    Vector3(Vector3 &&) {}

    Vector3 &operator=(const Vector3&) {}
    Vector3 &operator=(Vector3&&) {}
    
Vector3AndMain.cpp also contains the Main function, used to test the behaviour of the aforementioned class and struct.
