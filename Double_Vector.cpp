#include "Double_Vector.h"
#include<iostream>
using namespace std;
/*
private:
    double* internal_array;
    int array_size;
    int array_capacity;


    double* items;
    int sz;
    int array_capacity;
*/
Double_vector::Double_vector() :sz(0), array_capacity(100){
    items = new double[array_capacity];
}

Double_vector::Double_vector(double lst[], int n):array_capacity(n){
    items = new double[array_capacity];
    for (int i = 0; i < n; i++) {
        items[i] = lst[i];
    }
    sz = n;
}

Double_vector::Double_vector(int n, double val) :sz{ n }, array_capacity{ n } {
    items = new double[array_capacity];
    for (int i = 0; i < sz; i++) {
        items[i] = val;
    }
}

Double_vector::Double_vector(const Double_vector& x) : sz(x.sz), array_capacity(x.array_capacity) {
    items = new double[array_capacity];
    for (int i = 0; i < sz; ++i) {
        items[i] = x.items[i];
    }
}

Double_vector::~Double_vector() {
    delete[] items;
}

Double_vector& Double_vector::operator=(const Double_vector& x) {
    if (this != &x) {
        delete[] items;
        sz = x.sz;
        array_capacity = x.array_capacity;
        items = new double[array_capacity];
        for (int i = 0; i < sz; ++i) {
            items[i] = x.items[i];
        }
    }
    return *this;
}



void Double_vector::print()const {
    int i = 0;
    cout << "v={";
    for ( ; i < sz - 1; ) {
        cout << items[i]<<",";
        i++;
    }
    if(sz<=0)
        cout << "}"<<endl;
    else
        cout << items[i] << "}" << endl;
}

int Double_vector::size()const {
    return sz;
}

/*
int Double_vector::max_size() const {

}
*/

void Double_vector::resize(int n, double val) {
    int i;

    if(n > sz){
        if (n > array_capacity) {
            double* new_elements = new double[n];

            for (i = 0; i < sz; i++) {
                new_elements[i] = items[i];
            }

            for (i = sz; i < n; i++) {
                new_elements[i] = val;
            }

            delete[] items;
            items = new_elements;

            array_capacity = n;
        }

        else {
            for (i = sz; i < n; i++) {
                items[i] = val;
            }
        }
    }

    else {
        sz = n;
    }

    
}

int Double_vector::capacity() const {
    return array_capacity;
}

bool Double_vector::empty() const {
    if (sz == 0) {
        return true;
    }
    else {
        return false;
    }
}

void Double_vector::reserve(int n) {
    if (n <= array_capacity) {
        return;
    }
    else {
        double* new_elements = new double[n];

        int i;
        for (i = 0; i < sz; i++) {
            new_elements[i] = items[i];
        }

        delete[] items;

        items = new_elements;
        array_capacity = n;
    }
}

double& Double_vector::operator[](int pos) {
    if (pos < 0 || pos >= sz) {
        cout << "Index out of Range" << endl;
    }
    else {
        return items[pos];
    }
}

const double& Double_vector::operator[](int pos) const {
    if (pos < 0 || pos >= sz) {
        cout << "Index out of Range" << endl;
    }
    else {
        return items[pos];
    }
}

double& Double_vector::at(int pos) {
    if (pos < 0 || pos >= sz) {
        cout << "Index out of Range" << endl;
    }
    else {
        return items[pos]; 
    }
}

const double& Double_vector::at(int pos) const {
    if (pos < 0 || pos >= sz) {
        cout << "Index out of Range" << endl;
    }
    else {
        return items[pos];
    }
}

double& Double_vector::front() {
    if (empty()) {
        cout<<"Vector is empty"<<endl;
    }
    return items[0];
}

const double& Double_vector::front() const {
    if (empty()) {
        cout << "Vector is empty" << endl;
    }
    return items[0];
}

double& Double_vector::back() {
    if (empty()) {
        cout << "Vector is empty" << endl;
    }
    return items[sz - 1];
}

const double& Double_vector::back() const {
    if (empty()) {
        cout << "Vector is empty" << endl;
    }
    return items[sz - 1];
}

double* Double_vector::data() {
    return items;
}

const double* Double_vector::data() const {
    return items;
}




void Double_vector::push_back(const double& val) {
    if (sz < this->array_capacity) {
        items[sz] = val;
        sz++;
    }
    else {
        double *new_elements = new double[array_capacity * 2];
        array_capacity *= 2 ;
        for (int i = 0; i < sz; i++)
            new_elements[i] = items[i];
        delete []items;
        items = new_elements;
        items[sz] = val;
        sz++;
    }
}

void Double_vector::push_back( double ls[],int n) {
        double* new_elements = new double[array_capacity +n];
        array_capacity += n;
        for (int i = 0; i < sz; i++)
            new_elements[i] = items[i];
        delete[]items;
        items = new_elements;
        for (int i = 0; i < n; i++)
            items[i + sz] = ls[i];
        sz += n;
        
}

void Double_vector::pop_back() {
    if (sz > 0) {
        --sz;
        if (sz > 0) {
            double* new_array = new double[sz];
            for (int i = 0; i < sz; ++i) {
                new_array[i] = items[i];
            }
            delete[] items;
            items = new_array;
        }
        else {
            delete[] items;
            items = NULL;
        }
    }
}

void Double_vector::insert(int pos, double value) {
    if (pos < 0 || pos > sz) {
        cout << "Vector is empty" << endl;
    }

    if (sz == array_capacity) {
        if (array_capacity == 0) {
            reserve(1);
        }
        else {
            reserve(array_capacity * 2);
        }
    }

    int i;
    for (i = 0; i > pos; i--) {
        items[i] = items[i - 1];
    }

    items[pos] = value;
    ++sz;
}

void Double_vector::erase(int pos){
    if (pos < 0 || pos >= sz) {
        cout << "Vector is empty" << endl;
    }

    int i;
    for (i = pos; i < sz - 1; ++i) {
        items[i] = items[i + 1];
    }

    --sz;
}

void Double_vector::clear(){
    int i;
    for (i = 0; i < sz; i++) {
        pop_back();
    }
}



bool Double_vector::operator==(const Double_vector& rhs)const {
    if (this->sz != rhs.sz) return false;

    for (int i = 0; i < sz; i++)
        if (this->items[i] != rhs.items[i]) {
             return false;
        }
    return true;
    
}

bool Double_vector::operator!=(const Double_vector& rhs)const {
    
    return !(*this == rhs);

}

Double_vector Double_vector::operator+(const Double_vector &other)const {
    Double_vector res;
    int totalCap = this->sz + other.sz;
    if (res.array_capacity < totalCap) {
        res.array_capacity = totalCap;
        delete[]res.items;
    }
    int i;
    for ( i = 0; i < this->sz; i++)
        res.items[i] = this->items[i];
    res.sz = this->sz;
    for (i = 0; i < other.sz; i++)
        res.items[i + res.sz] = other.items[i];
    res.sz = this->sz + other.sz;
    this->print();
    other.print();
    res.print();
    return res;
}

void displayVectorInfo(const Double_vector& vec, const std::string& name) {
    std::cout << "Size of " << name << ": " << vec.size() << "\n";
    std::cout << "Capacity of " << name << ": " << vec.capacity() << "\n";
    std::cout << "Contents of " << name << ": ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n\n";
}

int main() {
    // Test Case 1: Default Constructor
    Double_vector vector1;
    std::cout << "Test Case 1 - Default Constructor:\n";
    displayVectorInfo(vector1, "vector1");

    // Test Case 2: Fill Constructor
    Double_vector vector2(5, 3.14);
    std::cout << "Test Case 2 - Fill Constructor:\n";
    displayVectorInfo(vector2, "vector2");

    // Test Case 3: Copy Constructor
    Double_vector vector3(vector2);
    std::cout << "Test Case 3 - Copy Constructor:\n";
    displayVectorInfo(vector3, "vector3");

    // Test Case 4: Overloaded Assignment Operator
    Double_vector vector4;
    vector4 = vector3;
    std::cout << "Test Case 4 - Overloaded Assignment Operator:\n";
    displayVectorInfo(vector4, "vector4");

    // Test Case 5: Resize Method
    vector1.resize(3, 1.1);
    std::cout << "Test Case 5 - Resize Method:\n";
    displayVectorInfo(vector1, "vector1");

    // Test Case 6: Push Back Method
    vector2.push_back(2.2);
    std::cout << "Test Case 6 - Push Back Method:\n";
    displayVectorInfo(vector2, "vector2");

    // Test Case 7: Pop Back Method
    vector3.pop_back();
    std::cout << "Test Case 7 - Pop Back Method:\n";
    displayVectorInfo(vector3, "vector3");

    // Test Case 8: Destructor (Manually Triggered)
    {
        Double_vector vector5(3, 5.5);
        std::cout << "Test Case 8 - Destructor (Manually Triggered):\n";
        displayVectorInfo(vector5, "vector5 (Before Destruction)");
    } // Destructor should be called here
    std::cout << "Vector5 has been destructed.\n\n";

    // Test Case 9: Resize to 0
    Double_vector vector6(3, 1.1);
    std::cout << "Test Case 9 - Resize to 0:\n";
    displayVectorInfo(vector6, "vector6 (Before Resize)");
    vector6.resize(0);
    displayVectorInfo(vector6, "vector6 (After Resize to 0)\n");

    // Test Case 10: Insert at the Beginning
    Double_vector vector7(3, 2.2);
    std::cout << "Test Case 10 - Insert at the Beginning:\n";
    displayVectorInfo(vector7, "vector7 (Before Insertion)");
    vector7.insert(0, 1.1);
    displayVectorInfo(vector7, "vector7 (After Insertion at Beginning)\n");

    // Test Case 11: Insert at the Middle
    std::cout << "Test Case 11 - Insert at the Middle:\n";
    displayVectorInfo(vector7, "vector7 (Before Insertion)");
    vector7.insert(2, 3.3);
    displayVectorInfo(vector7, "vector7 (After Insertion at Middle)\n");

    // Test Case 12: Accessing Elements at Invalid Indices
    std::cout << "Test Case 12 - Accessing Elements at Invalid Indices:\n";
    try {
        double element = vector7[10];  // Attempt to access an element at an invalid index
        // The following line should not be reached
        std::cout << "Element at index 10: " << element << "\n";  // This line should not be executed
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    return 0;
}
